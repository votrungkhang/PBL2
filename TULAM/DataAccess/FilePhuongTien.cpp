#include "FilePhuongTien.h"

#include <array>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace {
std::array<std::string, 5> tachDongPhuongTien(const std::string& dong) {
    std::array<std::string, 5> truong;
    std::size_t batDau = 0;

    for (std::size_t i = 0; i < 4; ++i) {
        const std::size_t viTri = dong.find('|', batDau);
        if (viTri == std::string::npos) {
            throw std::runtime_error(
                "Thieu truong du lieu phuong tien");
        }

        truong[i] = dong.substr(batDau, viTri - batDau);
        batDau = viTri + 1;
    }

    truong[4] = dong.substr(batDau);
    if (truong[4].find('|') != std::string::npos) {
        throw std::runtime_error(
            "Thua truong du lieu phuong tien");
    }

    return truong;
}

bool coKyTuPhanCachPhuongTien(const std::string& giaTri) {
    return giaTri.find_first_of("|\r\n") != std::string::npos;
}

double chuyenSangTaiTrong(const std::string& giaTri) {
    std::istringstream input(giaTri);
    double taiTrong;
    if (!(input >> taiTrong)) {
        throw std::runtime_error("Tai trong toi da khong hop le");
    }

    input >> std::ws;
    if (!input.eof() || !std::isfinite(taiTrong)) {
        throw std::runtime_error("Tai trong toi da khong hop le");
    }
    return taiTrong;
}
}

FILEPHUONGTIEN::FILEPHUONGTIEN(const std::string& nameFile)
    : IFILEPHUONGTIEN(nameFile) {}

bool FILEPHUONGTIEN::save(IPHUONGTIENREPOSITORY& repository) {
    const std::vector<const PHUONGTIEN*> danhSach = repository.getAll();
    for (const PHUONGTIEN* phuongTien : danhSach) {
        if (phuongTien == nullptr
            || coKyTuPhanCachPhuongTien(
                phuongTien->GetMaPhuongTien())
            || coKyTuPhanCachPhuongTien(phuongTien->GetBienSo())
            || coKyTuPhanCachPhuongTien(phuongTien->GetLoaiXe())
            || coKyTuPhanCachPhuongTien(phuongTien->GetTrangThai())
            || !std::isfinite(phuongTien->GetTaiTrongToiDa())) {
            return false;
        }
    }

    std::ofstream file(nameFile);
    if (!file.is_open()) {
        return false;
    }
    file << std::setprecision(
        std::numeric_limits<double>::max_digits10);

    for (const PHUONGTIEN* phuongTien : danhSach) {
        file << phuongTien->GetMaPhuongTien() << '|'
             << phuongTien->GetBienSo() << '|'
             << phuongTien->GetLoaiXe() << '|'
             << phuongTien->GetTaiTrongToiDa() << '|'
             << phuongTien->GetTrangThai() << '\n';
    }

    file.close();
    return !file.fail();
}

bool FILEPHUONGTIEN::read(IPHUONGTIENREPOSITORY& repository) {
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

            const std::array<std::string, 5> truong =
                tachDongPhuongTien(dong);
            if (truong[0].empty()) {
                throw std::runtime_error(
                    "Ma phuong tien khong duoc de trong");
            }
            if (repository.contains(truong[0])) {
                throw std::runtime_error(
                    "Ma phuong tien bi trung: " + truong[0]);
            }

            std::unique_ptr<PHUONGTIEN> phuongTien =
                std::make_unique<PHUONGTIEN>(
                    truong[0], truong[1], truong[2],
                    chuyenSangTaiTrong(truong[3]), truong[4]);
            if (!repository.add(std::move(phuongTien))) {
                return false;
            }
        }

        if (file.bad()) {
            return false;
        }
        return true;
    } catch (const std::exception& loi) {
        std::cerr << "Loi doc file phuong tien: "
                  << loi.what() << '\n';
        return false;
    }
}
