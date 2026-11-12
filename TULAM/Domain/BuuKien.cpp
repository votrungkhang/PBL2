#include "BuuKien.h"

BUUKIEN::BUUKIEN(
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
const string& BUUKIEN::GetMaBuuKien() const {
    return ma_buu_kien;
}

void BUUKIEN::SetMaBuuKien(const string& ma_moi) {
    ma_buu_kien = ma_moi;
}

// Loai buu kien
const string& BUUKIEN::GetLoaiBuuKien() const {
    return loai_buu_kien;
}

void BUUKIEN::SetLoaiBuuKien(const string& loai_moi) {
   loai_buu_kien = loai_moi;
}


// Trong luong
double BUUKIEN::GetTrongLuong() const {
    return trong_luong;
}

void BUUKIEN::SetTrongLuong(const double& trong_luong_moi) {
    trong_luong = trong_luong_moi;
}

// Dia chi gui
const string& BUUKIEN::GetDiaChiGui() const {
    return dia_chi_gui;
}

void BUUKIEN::SetDiaChiGui(const string& dia_chi_moi) {
    dia_chi_gui = dia_chi_moi;
}

// Dia chi nhan
const string& BUUKIEN::GetDiaChiNhan() const {
    return dia_chi_nhan;
}

void BUUKIEN::SetDiaChiNhan(const string& dia_chi_moi) {
    dia_chi_nhan = dia_chi_moi;
}

// Ngay gui
const string& BUUKIEN::GetNgayGui() const {
    return ngay_gui;
}

void BUUKIEN::SetNgayGui(const string& ngay_moi) {
    ngay_gui = ngay_moi;
}

// Trang thai
const string& BUUKIEN::GetTrangThai() const {
    return trang_thai;
}

void BUUKIEN::SetTrangThai(const string& trang_thai_moi) {
    trang_thai = trang_thai_moi;
}

// Ma nguoi gui
const string& BUUKIEN::GetMaNguoiGui() const {
    return ma_nguoi_gui;
}

void BUUKIEN::SetMaNguoiGui(const string& ma_nguoi_moi) {
    ma_nguoi_gui = ma_nguoi_moi;
}

// Ma nguoi nhan
const string& BUUKIEN::GetMaNguoiNhan() const {
    return ma_nguoi_nhan;
}

void BUUKIEN::SetMaNguoiNhan(const string& ma_nguoi_moi) {
    ma_nguoi_nhan = ma_nguoi_moi;
}

// Ma nhan vien tiep nhan
const string& BUUKIEN::GetMaNhanVienTiepNhan() const {
    return ma_nhan_vien_tiep_nhan;
}

void BUUKIEN::SetMaNhanVienTiepNhan(const string& ma_nv_Moi) {
    ma_nhan_vien_tiep_nhan = ma_nv_Moi;
}

// Ma chuyen
const string& BUUKIEN::GetMaChuyen() const {
    return ma_chuyen;
}

void BUUKIEN::SetMaChuyen(const string& ma_chuyen_moi) {
    ma_chuyen = ma_chuyen_moi;
}

// Thoi gian giao du kien
const string& BUUKIEN::GetThoiGianGiaoDuKien() const{
    return thoi_gian_giao_du_kien;
}

void BUUKIEN::SetThoiGianGiaoDuKien(const string& thoi_gian_moi) {
    thoi_gian_giao_du_kien = thoi_gian_moi;
}

// Phi dich vu
double BUUKIEN::GetPhiDichVu() const {
    return phi_dich_vu;
}

void BUUKIEN::SetPhiDichVu(const double& phi_moi) {
    phi_dich_vu = phi_moi;
}

// Tong phi
double BUUKIEN::GetTongPhi() const {
    return tong_phi;
}

void BUUKIEN::SetTongPhi(const double& tong_phi_moi) {
    tong_phi = tong_phi_moi;
}
