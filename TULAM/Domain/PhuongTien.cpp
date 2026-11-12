#include "PhuongTien.h"

PHUONGTIEN::PHUONGTIEN(
    const std::string& ma_phuong_tien,
    const std::string& bien_so,
    const std::string& loai_xe,
    double tai_trong_toi_da,
    const std::string& trang_thai)
    : ma_phuong_tien(ma_phuong_tien),
      bien_so(bien_so),
      loai_xe(loai_xe),
      tai_trong_toi_da(tai_trong_toi_da),
      trang_thai(trang_thai) {}

const std::string& PHUONGTIEN::GetMaPhuongTien() const {
    return ma_phuong_tien;
}

void PHUONGTIEN::SetMaPhuongTien(
    const std::string& maPhuongTienMoi) {
    ma_phuong_tien = maPhuongTienMoi;
}

const std::string& PHUONGTIEN::GetBienSo() const {
    return bien_so;
}

void PHUONGTIEN::SetBienSo(const std::string& bienSoMoi) {
    bien_so = bienSoMoi;
}

const std::string& PHUONGTIEN::GetLoaiXe() const {
    return loai_xe;
}

void PHUONGTIEN::SetLoaiXe(const std::string& loaiXeMoi) {
    loai_xe = loaiXeMoi;
}

double PHUONGTIEN::GetTaiTrongToiDa() const {
    return tai_trong_toi_da;
}

void PHUONGTIEN::SetTaiTrongToiDa(double taiTrongToiDaMoi) {
    tai_trong_toi_da = taiTrongToiDaMoi;
}

const std::string& PHUONGTIEN::GetTrangThai() const {
    return trang_thai;
}

void PHUONGTIEN::SetTrangThai(const std::string& trangThaiMoi) {
    trang_thai = trangThaiMoi;
}
