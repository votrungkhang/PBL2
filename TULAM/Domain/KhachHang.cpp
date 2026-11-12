#include "KhachKhang.h"

KHACHHANG::KHACHHANG(
    const string& ma_khach_hang,
    const string& ho_ten,
    const string& sdt,
    const string& dia_chi)
    : ma_khach_hang(ma_khach_hang),
      ho_ten(ho_ten),
      sdt(sdt),
      dia_chi(dia_chi) {}

const string& KHACHHANG::GetMaKhachHang() const {
    return ma_khach_hang;
}

void KHACHHANG::SetMaKhachHang(const string& maKhachHangMoi) {
    ma_khach_hang = maKhachHangMoi;
}

const string& KHACHHANG::GetHoTen() const {
    return ho_ten;
}

void KHACHHANG::SetHoTen(const string& hoTenMoi) {
    ho_ten = hoTenMoi;
}

const string& KHACHHANG::GetSdt() const {
    return sdt;
}

void KHACHHANG::SetSdt(const string& sdtMoi) {
    sdt = sdtMoi;
}

const string& KHACHHANG::GetDiaChi() const {
    return dia_chi;
}

void KHACHHANG::SetDiaChi(const string& diaChiMoi) {
    dia_chi = diaChiMoi;
}