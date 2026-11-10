#include "BuuKienBinhThuong.h"

BuuKienBinhThuong::BuuKienBinhThuong(
    const std::string& maBuuKien,
    const std::string& thoiGianGiaoDuKien)
    : BuuKien(maBuuKien),
      thoiGianGiaoDuKien(thoiGianGiaoDuKien) {}

std::string BuuKienBinhThuong::getLoai() const {
    return "Buu kien binh thuong";
}

const std::string& BuuKienBinhThuong::getThoiGianGiaoDuKien() const {
    return thoiGianGiaoDuKien;
}
