#include "NhanVien.h"

NHANVIEN::NHANVIEN(
    const string& ma_nhan_vien,
    const string& ho_ten,
    const string& chuc_vu,
    const string& sdt)
    : ma_nhan_vien(ma_nhan_vien),
      ho_ten(ho_ten),
      chuc_vu(chuc_vu),
      sdt(sdt) {}

const string& NHANVIEN::GetMaNhanVien() const {
    return ma_nhan_vien;
}

void NHANVIEN::SetMaNhanVien(const string& maNhanVienMoi) {
    ma_nhan_vien = maNhanVienMoi;
}

const string& NHANVIEN::GetHoTen() const {
    return ho_ten;
}

void NHANVIEN::SetHoTen(const string& hoTenMoi) {
    ho_ten = hoTenMoi;
}

const string& NHANVIEN::GetChucVu() const {
    return chuc_vu;
}

void NHANVIEN::SetChucVu(const string& chucVuMoi) {
    chuc_vu = chucVuMoi;
}

const string& NHANVIEN::GetSdt() const {
    return sdt;
}

void NHANVIEN::SetSdt(const string& sdtMoi) {
    sdt = sdtMoi;
}
