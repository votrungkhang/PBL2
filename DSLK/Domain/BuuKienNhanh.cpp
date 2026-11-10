#include "BuuKienNhanh.h"

BuuKienNhanh::BuuKienNhanh(
    const std::string& maBuuKien,
    const std::string& thoiGianGiaoDuKien)
    : BuuKien(maBuuKien),
      thoiGianGiaoDuKien(thoiGianGiaoDuKien) {}

std::string BuuKienNhanh::getLoai() const {
    return "Buu kien nhanh";
}

const std::string& BuuKienNhanh::getThoiGianGiaoDuKien() const {
    return thoiGianGiaoDuKien;
}
