#include "FileBuuKienRepository.h"

#include <fstream>
#include <stdexcept>
#include <utility>
#include "../Domain/BuuKienBinhThuong.h"
#include "../Domain/BuuKienHoaToc.h"
#include "../Domain/BuuKienNhanh.h"

namespace {

std::unique_ptr<BuuKien> createBuuKien(
    const std::string& loai,
    const std::string& maBuuKien,
    const std::string& thoiGianGiaoDuKien) {
    if (loai == "Buu kien binh thuong") {
        return std::unique_ptr<BuuKien>(
            new BuuKienBinhThuong(maBuuKien, thoiGianGiaoDuKien));
    }
    if (loai == "Buu kien hoa toc") {
        return std::unique_ptr<BuuKien>(
            new BuuKienHoaToc(maBuuKien, thoiGianGiaoDuKien));
    }
    if (loai == "Buu kien nhanh") {
        return std::unique_ptr<BuuKien>(
            new BuuKienNhanh(maBuuKien, thoiGianGiaoDuKien));
    }

    throw std::runtime_error("Loai buu kien khong hop le trong file.");
}

} // namespace

FileBuuKienRepository::FileBuuKienRepository(const std::string& filePath)
    : filePath(filePath) {
    load();
}

void FileBuuKienRepository::load() {
    std::ifstream input(filePath.c_str());
    if (!input.is_open()) {
        std::ofstream createFile(filePath.c_str(), std::ios::app);
        if (!createFile.is_open()) {
            throw std::runtime_error(
                "Khong the mo hoac tao file du lieu: " + filePath);
        }
        return;
    }

    std::string loai;
    std::string maBuuKien;
    std::string thoiGianGiaoDuKien;
    while (std::getline(input, loai)) {
        if (loai.empty()) {
            continue;
        }
        if (!std::getline(input, maBuuKien) || maBuuKien.empty() ||
            !std::getline(input, thoiGianGiaoDuKien)) {
            throw std::runtime_error(
                "Du lieu trong file khong dung dinh dang: " + filePath);
        }

        std::unique_ptr<BuuKien> buuKien =
            createBuuKien(loai, maBuuKien, thoiGianGiaoDuKien);
        if (storage.contains(maBuuKien)) {
            throw std::runtime_error(
                "Ma buu kien bi trung trong file: " + maBuuKien);
        }
        storage.add(std::move(buuKien));
    }

    if (input.bad()) {
        throw std::runtime_error("Loi khi doc file du lieu: " + filePath);
    }
}

void FileBuuKienRepository::save() const {
    const std::vector<const BuuKien*> buuKiens = storage.getAll();
    for (const BuuKien* buuKien : buuKiens) {
        const std::string& maBuuKien = buuKien->getMaBuuKien();
        const std::string& thoiGianGiaoDuKien =
            buuKien->getThoiGianGiaoDuKien();
        if (maBuuKien.find('\n') != std::string::npos ||
            maBuuKien.find('\r') != std::string::npos ||
            thoiGianGiaoDuKien.find('\n') != std::string::npos ||
            thoiGianGiaoDuKien.find('\r') != std::string::npos) {
            throw std::runtime_error(
                "Du lieu buu kien khong duoc chua ky tu xuong dong.");
        }
    }

    std::ofstream output(filePath.c_str(), std::ios::trunc);
    if (!output.is_open()) {
        throw std::runtime_error("Khong the ghi file du lieu: " + filePath);
    }

    for (const BuuKien* buuKien : buuKiens) {
        output << buuKien->getLoai() << '\n'
               << buuKien->getMaBuuKien() << '\n'
               << buuKien->getThoiGianGiaoDuKien() << '\n';
    }
    output.flush();
    if (!output) {
        throw std::runtime_error("Loi khi ghi file du lieu: " + filePath);
    }
}

bool FileBuuKienRepository::add(std::unique_ptr<BuuKien> buuKien) {
    if (!buuKien || contains(buuKien->getMaBuuKien())) {
        return false;
    }

    return storage.add(std::move(buuKien));
}

bool FileBuuKienRepository::contains(
    const std::string& maBuuKien) const {
    return storage.contains(maBuuKien);
}

std::vector<const BuuKien*> FileBuuKienRepository::getAll() const {
    return storage.getAll();
}
