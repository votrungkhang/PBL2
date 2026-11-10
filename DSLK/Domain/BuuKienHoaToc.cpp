#include "BuuKienHoaToc.h"

BuuKienHoaToc::BuuKienHoaToc(
    const std::string& maBuuKien,
    const std::string& thoiGianGiaoDuKien)
    : BuuKien(maBuuKien),
      thoiGianGiaoDuKien(thoiGianGiaoDuKien) {}

std::string BuuKienHoaToc::getLoai() const {
    return "Buu kien hoa toc";
}

const std::string& BuuKienHoaToc::getThoiGianGiaoDuKien() const {
    return thoiGianGiaoDuKien;
}
