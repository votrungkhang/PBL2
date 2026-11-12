#include "FileKhachHang.h"

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
            throw std::runtime_error("Thieu truong du lieu khach hang");
        }

        truong[i] = dong.substr(batDau, viTri - batDau);
        batDau = viTri + 1;
    }

    truong[3] = dong.substr(batDau);
    if (truong[3].find('|') != std::string::npos) {
        throw std::runtime_error("Thua truong du lieu khach hang");
    }

    return truong;
}

bool coKyTuPhanCach(const std::string& giaTri) {
    return giaTri.find_first_of("|\r\n") != std::string::npos;
}
}

FILEKHACHHANG::FILEKHACHHANG(const std::string& nameFile)
    : IFILEKHACHHANG(nameFile) {}

bool FILEKHACHHANG::save(IKHACHHANGREPOSITORY& repository) {
    const std::vector<const KHACHHANG*> danhSach = repository.getAll();
    for (const KHACHHANG* khachHang : danhSach) {
        if (khachHang == nullptr
            || coKyTuPhanCach(khachHang->GetMaKhachHang())
            || coKyTuPhanCach(khachHang->GetHoTen())
            || coKyTuPhanCach(khachHang->GetSdt())
            || coKyTuPhanCach(khachHang->GetDiaChi())) {
            return false;
        }
    }

    std::ofstream file(nameFile);
    if (!file.is_open()) {
        return false;
    }

    for (const KHACHHANG* khachHang : danhSach) {
        file << khachHang->GetMaKhachHang() << '|'
             << khachHang->GetHoTen() << '|'
             << khachHang->GetSdt() << '|'
             << khachHang->GetDiaChi() << '\n';
    }

    file.close();
    return !file.fail();
}

bool FILEKHACHHANG::read(IKHACHHANGREPOSITORY& repository) {
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
                throw std::runtime_error("Ma khach hang khong duoc de trong");
            }
            if (repository.contains(truong[0])) {
                throw std::runtime_error(
                    "Ma khach hang bi trung: " + truong[0]);
            }

            std::unique_ptr<KHACHHANG> khachHang =
                std::make_unique<KHACHHANG>(
                    truong[0], truong[1], truong[2], truong[3]);
            if (!repository.add(std::move(khachHang))) {
                return false;
            }
        }

        if (file.bad()) {
            return false;
        }
        return true;
    } catch (const std::exception& loi) {
        std::cerr << "Loi doc file khach hang: "
                  << loi.what() << '\n';
        return false;
    }
}