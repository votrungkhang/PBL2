#include "ChuyenXe.h"

CHUYENXE::CHUYENXE(
    const std::string& ngay_van_chuyen,
    const std::string& dia_chi_xuat_phat,
    const std::string& dia_chi_den,
    const std::string& ma_tai_xe,
    const std::string& ma_phuong_tien,
    const std::string& trang_thai,
    IBUUKIENREPOSITORY* ds_buu_kien)
    : ngay_van_chuyen(ngay_van_chuyen),
      dia_chi_xuat_phat(dia_chi_xuat_phat),
      dia_chi_den(dia_chi_den),
      ma_tai_xe(ma_tai_xe),
      ma_phuong_tien(ma_phuong_tien),
      trang_thai(trang_thai),
      ds_buu_kien(ds_buu_kien) {}

const std::string& CHUYENXE::GetNgayVanChuyen() const {
    return ngay_van_chuyen;
}

void CHUYENXE::SetNgayVanChuyen(
    const std::string& ngayVanChuyenMoi) {
    ngay_van_chuyen = ngayVanChuyenMoi;
}

const std::string& CHUYENXE::GetDiaChiXuatPhat() const {
    return dia_chi_xuat_phat;
}

void CHUYENXE::SetDiaChiXuatPhat(
    const std::string& diaChiXuatPhatMoi) {
    dia_chi_xuat_phat = diaChiXuatPhatMoi;
}

const std::string& CHUYENXE::GetDiaChiDen() const {
    return dia_chi_den;
}

void CHUYENXE::SetDiaChiDen(const std::string& diaChiDenMoi) {
    dia_chi_den = diaChiDenMoi;
}

const std::string& CHUYENXE::GetMaTaiXe() const {
    return ma_tai_xe;
}

void CHUYENXE::SetMaTaiXe(const std::string& maTaiXeMoi) {
    ma_tai_xe = maTaiXeMoi;
}

const std::string& CHUYENXE::GetMaPhuongTien() const {
    return ma_phuong_tien;
}

void CHUYENXE::SetMaPhuongTien(
    const std::string& maPhuongTienMoi) {
    ma_phuong_tien = maPhuongTienMoi;
}

const std::string& CHUYENXE::GetTrangThai() const {
    return trang_thai;
}

void CHUYENXE::SetTrangThai(const std::string& trangThaiMoi) {
    trang_thai = trangThaiMoi;
}

IBUUKIENREPOSITORY* CHUYENXE::GetDsBuuKien() const {
    return ds_buu_kien;
}

void CHUYENXE::SetDsBuuKien(
    IBUUKIENREPOSITORY& dsBuuKienMoi) {
    ds_buu_kien = &dsBuuKienMoi;
}
