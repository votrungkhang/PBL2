#include "FileTaiXe.h"

#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <utility>

namespace {
std::array<std::string, 4> tachDongTaiXe(const std::string& dong) {
    std::array<std::string, 4> truong;
    std::size_t batDau = 0;

    for (std::size_t i = 0; i < 3; ++i) {
        const std::size_t viTri = dong.find('|', batDau);
        if (viTri == std::string::npos) {
            throw std::runtime_error("Thieu truong du lieu tai xe");
        }

        truong[i] = dong.substr(batDau, viTri - batDau);
        batDau = viTri + 1;
    }

    truong[3] = dong.substr(batDau);
    if (truong[3].find('|') != std::string::npos) {
        throw std::runtime_error("Thua truong du lieu tai xe");
    }

    return truong;
}

bool coKyTuPhanCachTaiXe(const std::string& giaTri) {
    return giaTri.find_first_of("|\r\n") != std::string::npos;
}
}

FILETAIXE::FILETAIXE(const std::string& nameFile)
    : IFILETAIXE(nameFile) {}

bool FILETAIXE::save(ITAIXEREPOSITORY& repository) {
    const std::vector<const TAIXE*> danhSach = repository.getAll();
    for (const TAIXE* taiXe : danhSach) {
        if (taiXe == nullptr
            || coKyTuPhanCachTaiXe(taiXe->GetMaTaiXe())
            || coKyTuPhanCachTaiXe(taiXe->GetHoTen())
            || coKyTuPhanCachTaiXe(taiXe->GetSdt())
            || coKyTuPhanCachTaiXe(taiXe->GetBangLai())) {
            return false;
        }
    }

    std::ofstream file(nameFile);
    if (!file.is_open()) {
        return false;
    }

    for (const TAIXE* taiXe : danhSach) {
        file << taiXe->GetMaTaiXe() << '|'
             << taiXe->GetHoTen() << '|'
             << taiXe->GetSdt() << '|'
             << taiXe->GetBangLai() << '\n';
    }

    file.close();
    return !file.fail();
}

bool FILETAIXE::read(ITAIXEREPOSITORY& repository) {
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

            const std::array<std::string, 4> truong =
                tachDongTaiXe(dong);
            if (truong[0].empty()) {
                throw std::runtime_error("Ma tai xe khong duoc de trong");
            }
            if (repository.contains(truong[0])) {
                throw std::runtime_error(
                    "Ma tai xe bi trung: " + truong[0]);
            }

            std::unique_ptr<TAIXE> taiXe =
                std::make_unique<TAIXE>(
                    truong[0], truong[1], truong[2], truong[3]);
            if (!repository.add(std::move(taiXe))) {
                return false;
            }
        }

        if (file.bad()) {
            return false;
        }
        return true;
    } catch (const std::exception& loi) {
        std::cerr << "Loi doc file tai xe: "
                  << loi.what() << '\n';
        return false;
    }
}
