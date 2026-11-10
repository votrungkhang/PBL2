#include "BuuKien.h"

BuuKien::BuuKien(
    const string& maBuuKien,
    LoaiBuuKien loaiBuuKien,
    double trongLuong,
    const string& diaChiGui,
    const string& diaChiNhan,
    const string& ngayGui,
    const string& trangThai,
    const string& maNguoiGui,
    const string& maNguoiNhan,
    const string& maNhanVienTiepNhan,
    const string& maChuyen,
    const string& thoiGianGiaoDuKien,
    double phiDichVu,
    double tongphi)
    : loaiBuuKien(loaiBuuKien),
      maBuuKien(maBuuKien),
      trongLuong(trongLuong),
      diaChiGui(diaChiGui),
      diaChiNhan(diaChiNhan),
      ngayGui(ngayGui),
      trangThai(trangThai),
      maNguoiGui(maNguoiGui),
      maNguoiNhan(maNguoiNhan),
      maNhanVienTiepNhan(maNhanVienTiepNhan),
      maChuyen(maChuyen),
      thoiGianGiaoDuKien(thoiGianGiaoDuKien),
      phiDichVu(phiDichVu),
      tongphi(tongphi) {}

// Loai buu kien
LoaiBuuKien BuuKien::getLoaiBuuKien() const {
    return loaiBuuKien;
}

void BuuKien::setLoaiBuuKien(LoaiBuuKien loaiBuuKienMoi) {
    loaiBuuKien = loaiBuuKienMoi;
}

// Ma buu kien
const string& BuuKien::getMaBuuKien() const {
    return maBuuKien;
}

void BuuKien::setMaBuuKien(const string& maBuuKienMoi) {
    maBuuKien = maBuuKienMoi;
}

// Trong luong
double BuuKien::getTrongLuong() const {
    return trongLuong;
}

void BuuKien::setTrongLuong(double trongLuongMoi) {
    trongLuong = trongLuongMoi;
}

// Dia chi gui
const string& BuuKien::getDiaChiGui() const {
    return diaChiGui;
}

void BuuKien::setDiaChiGui(const string& diaChiGuiMoi) {
    diaChiGui = diaChiGuiMoi;
}

// Dia chi nhan
const string& BuuKien::getDiaChiNhan() const {
    return diaChiNhan;
}

void BuuKien::setDiaChiNhan(const string& diaChiNhanMoi) {
    diaChiNhan = diaChiNhanMoi;
}

// Ngay gui
const string& BuuKien::getNgayGui() const {
    return ngayGui;
}

void BuuKien::setNgayGui(const string& ngayGuiMoi) {
    ngayGui = ngayGuiMoi;
}

// Trang thai
const string& BuuKien::getTrangThai() const {
    return trangThai;
}

void BuuKien::setTrangThai(const string& trangThaiMoi) {
    trangThai = trangThaiMoi;
}

// Ma nguoi gui
const string& BuuKien::getMaNguoiGui() const {
    return maNguoiGui;
}

void BuuKien::setMaNguoiGui(const string& maNguoiGuiMoi) {
    maNguoiGui = maNguoiGuiMoi;
}

// Ma nguoi nhan
const string& BuuKien::getMaNguoiNhan() const {
    return maNguoiNhan;
}

void BuuKien::setMaNguoiNhan(const string& maNguoiNhanMoi) {
    maNguoiNhan = maNguoiNhanMoi;
}

// Ma nhan vien tiep nhan
const string& BuuKien::getMaNhanVienTiepNhan() const {
    return maNhanVienTiepNhan;
}

void BuuKien::setMaNhanVienTiepNhan(const string& maNhanVienTiepNhanMoi) {
    maNhanVienTiepNhan = maNhanVienTiepNhanMoi;
}

// Ma chuyen
const string& BuuKien::getMaChuyen() const {
    return maChuyen;
}

void BuuKien::setMaChuyen(const string& maChuyenMoi) {
    maChuyen = maChuyenMoi;
}

// Thoi gian giao du kien
const string& BuuKien::getThoiGianGiaoDuKien() const{
    return thoiGianGiaoDuKien;
}

void BuuKien::setThoiGianGiaoDuKien(const string& thoiGianGiaoDuKienMoi) {
    thoiGianGiaoDuKien = thoiGianGiaoDuKienMoi;
}

// Phi dich vu
double BuuKien::getPhiDichVu() const {
    return phiDichVu;
}

void BuuKien::setPhiDichVu(double phiDichVuMoi) {
    phiDichVu = phiDichVuMoi;
}

// Tong phi
double BuuKien::getTongPhi() const {
    return tongphi;
}

void BuuKien::setTongPhi(double tongPhiMoi) {
    tongphi = tongPhiMoi;
}
