#include "BuuKien.h"

BuuKien::BuuKien(
    const string& ma_buu_kien,
    const string& loai_buu_kien,
    const double& trong_luong,
    const string& dia_chi_gui,
    const string& dia_chi_nhan,
    const string& ngay_gui,
    const string& trang_thai,
    const string& ma_nguoi_gui,
    const string& ma_nguoi_nhan,
    const string& ma_nhan_vien_tiep_nhan,
    const string& ma_chuyen,
    const string& thoi_gian_giao_du_kien,
    const double& phi_dich_vu,
    const double& tong_phi)
    : ma_buu_kien(ma_buu_kien),
      loai_buu_kien(loai_buu_kien),
      trong_luong(trong_luong),
      dia_chi_gui(dia_chi_gui),
      dia_chi_nhan(dia_chi_nhan),
      ngay_gui(ngay_gui),
      trang_thai(trang_thai),
      ma_nguoi_gui(ma_nguoi_gui),
      ma_nguoi_nhan(ma_nguoi_nhan),
      ma_nhan_vien_tiep_nhan(ma_nhan_vien_tiep_nhan),
      ma_chuyen(ma_chuyen),
      thoi_gian_giao_du_kien(thoi_gian_giao_du_kien),
      phi_dich_vu(phi_dich_vu),
      tong_phi(tong_phi) {}

      
// Ma buu kien
const string& BuuKien::GetMaBuuKien() const {
    return ma_buu_kien;
}

void BuuKien::SetMaBuuKien(const string& ma_moi) {
    ma_buu_kien = ma_moi;
}

// Loai buu kien
const string& BuuKien::GetLoaiBuuKien() const {
    return loai_buu_kien;
}

void BuuKien::SetLoaiBuuKien(const string& loai_moi) {
   loai_buu_kien = loai_moi;
}


// Trong luong
double BuuKien::GetTrongLuong() const {
    return trong_luong;
}

void BuuKien::SetTrongLuong(const double& trong_luong_moi) {
    trong_luong = trong_luong_moi;
}

// Dia chi gui
const string& BuuKien::GetDiaChiGui() const {
    return dia_chi_gui;
}

void BuuKien::SetDiaChiGui(const string& dia_chi_moi) {
    dia_chi_gui = dia_chi_moi;
}

// Dia chi nhan
const string& BuuKien::GetDiaChiNhan() const {
    return dia_chi_nhan;
}

void BuuKien::SetDiaChiNhan(const string& dia_chi_moi) {
    dia_chi_nhan = dia_chi_moi;
}

// Ngay gui
const string& BuuKien::GetNgayGui() const {
    return ngay_gui;
}

void BuuKien::SetNgayGui(const string& ngay_moi) {
    ngay_gui = ngay_moi;
}

// Trang thai
const string& BuuKien::GetTrangThai() const {
    return trang_thai;
}

void BuuKien::SetTrangThai(const string& trang_thai_moi) {
    trang_thai = trang_thai_moi;
}

// Ma nguoi gui
const string& BuuKien::GetMaNguoiGui() const {
    return ma_nguoi_gui;
}

void BuuKien::SetMaNguoiGui(const string& ma_nguoi_moi) {
    ma_nguoi_gui = ma_nguoi_moi;
}

// Ma nguoi nhan
const string& BuuKien::GetMaNguoiNhan() const {
    return ma_nguoi_nhan;
}

void BuuKien::SetMaNguoiNhan(const string& ma_nguoi_moi) {
    ma_nguoi_nhan = ma_nguoi_moi;
}

// Ma nhan vien tiep nhan
const string& BuuKien::GetMaNhanVienTiepNhan() const {
    return ma_nhan_vien_tiep_nhan;
}

void BuuKien::SetMaNhanVienTiepNhan(const string& ma_nv_Moi) {
    ma_nhan_vien_tiep_nhan = ma_nv_Moi;
}

// Ma chuyen
const string& BuuKien::GetMaChuyen() const {
    return ma_chuyen;
}

void BuuKien::SetMaChuyen(const string& ma_chuyen_moi) {
    ma_chuyen = ma_chuyen_moi;
}

// Thoi gian giao du kien
const string& BuuKien::GetThoiGianGiaoDuKien() const{
    return thoi_gian_giao_du_kien;
}

void BuuKien::SetThoiGianGiaoDuKien(const string& thoi_gian_moi) {
    thoi_gian_giao_du_kien = thoi_gian_moi;
}

// Phi dich vu
double BuuKien::GetPhiDichVu() const {
    return phi_dich_vu;
}

void BuuKien::SetPhiDichVu(const double& phi_moi) {
    phi_dich_vu = phi_moi;
}

// Tong phi
double BuuKien::GetTongPhi() const {
    return tong_phi;
}

void BuuKien::SetTongPhi(const double& tong_phi_moi) {
    tong_phi = tong_phi_moi;
}
