#include "FileNhanVien.h"

#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <utility>

namespace {
std::array<std::string, 4> tachDong(const std::string& dong) {
    std::array<std::string, 4> truong;
    std::size_t batDau = 0;

    for (std::size_t i = 0; i < 3; ++i) {
        const std::size_t viTri = dong.find('|', batDau);
        if (viTri == std::string::npos) {
            throw std::runtime_error("Thieu truong du lieu nhan vien");
        }

        truong[i] = dong.substr(batDau, viTri - batDau);
        batDau = viTri + 1;
    }

    truong[3] = dong.substr(batDau);
    if (truong[3].find('|') != std::string::npos) {
        throw std::runtime_error("Thua truong du lieu nhan vien");
    }

    return truong;
}

bool coKyTuPhanCach(const std::string& giaTri) {
    return giaTri.find_first_of("|\r\n") != std::string::npos;
}
}

FILENHANVIEN::FILENHANVIEN(const std::string& nameFile)
    : IFILENHANVIEN(nameFile) {}

bool FILENHANVIEN::save(INHANVIENREPOSITORY& repository) {
    const std::vector<const NHANVIEN*> danhSach = repository.getAll();
    for (const NHANVIEN* nhanVien : danhSach) {
        if (nhanVien == nullptr
            || coKyTuPhanCach(nhanVien->GetMaNhanVien())
            || coKyTuPhanCach(nhanVien->GetHoTen())
            || coKyTuPhanCach(nhanVien->GetChucVu())
            || coKyTuPhanCach(nhanVien->GetSdt())) {
            return false;
        }
    }

    std::ofstream file(nameFile);
    if (!file.is_open()) {
        return false;
    }

    for (const NHANVIEN* nhanVien : danhSach) {
        file << nhanVien->GetMaNhanVien() << '|'
             << nhanVien->GetHoTen() << '|'
             << nhanVien->GetChucVu() << '|'
             << nhanVien->GetSdt() << '\n';
    }

    file.close();
    return !file.fail();
}

bool FILENHANVIEN::read(INHANVIENREPOSITORY& repository) {
    std::ifstream file(nameFile);
    if (!file.is_open()) {
        return false;
    }

    std::string dong;
    try {
        while (std::getline(file, dong)) {
            if (dong.empty()) {
                continue;
            }

            const std::array<std::string, 4> truong = tachDong(dong);
            if (truong[0].empty()) {
                throw std::runtime_error("Ma nhan vien khong duoc de trong");
            }
            if (repository.contains(truong[0])) {
                throw std::runtime_error(
                    "Ma nhan vien bi trung: " + truong[0]);
            }

            std::unique_ptr<NHANVIEN> nhanVien =
                std::make_unique<NHANVIEN>(
                    truong[0], truong[1], truong[2], truong[3]);
            if (!repository.add(std::move(nhanVien))) {
                return false;
            }
        }

        if (file.bad()) {
            return false;
        }
        return true;
    } catch (const std::exception& loi) {
        std::cerr << "Loi doc file nhan vien: "
                  << loi.what() << '\n';
        return false;
    }
}
