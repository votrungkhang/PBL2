#ifndef BUUKIEN_H
#define BUUKIEN_H

#include <string>
using namespace std;
#include "Enums.h"

class BuuKien {
protected:
    string ma_buu_kien;
    string loai_buu_kien;
    double trong_luong;
    string dia_chi_gui;
    string dia_chi_nhan;
    string ngay_gui;
    string trang_thai;
    string ma_nguoi_gui;
    string ma_nguoi_nhan;
    string ma_nhan_vien_tiep_nhan;
    string ma_chuyen;
    string thoi_gian_giao_du_kien;
    double phi_dich_vu;
    double tong_phi;

public:
    virtual ~BuuKien() = default;

    BuuKien(
        const string& ma_buu_kien = "",
        const string& loai_buu_kien = "",
        const double& trong_luong = 0,
        const string& dia_chi_gui = "",
        const string& dia_chi_nhan = "",
        const string& ngay_gui = "",
        const string& trang_thai = "",
        const string& ma_nguoi_gui = "",
        const string& ma_nguoi_nhan = "",
        const string& ma_nhan_vien_tiep_nhan = "",
        const string& ma_chuyen = "",
        const string& thoi_gian_giao_du_kien = "",
        const double& phi_dich_vu =0,
        const double& tong_phi = 0);

        
    // Ma buu kien
    const string& GetMaBuuKien() const;
    void SetMaBuuKien(const string& maBuuKienMoi);

    // Loai buu kien
    const string& GetLoaiBuuKien() const;
    void SetLoaiBuuKien(const string& loaiBuuKienMoi);
        
    // Trong luong
    double GetTrongLuong() const;
    void SetTrongLuong(const double& trongLuongMoi);

    // Dia chi gui
    const string& GetDiaChiGui() const;
    void SetDiaChiGui(const string& diaChiGuiMoi);

    // Dia chi nhan
    const string& GetDiaChiNhan() const;
    void SetDiaChiNhan(const string& diaChiNhanMoi);

    // Ngay gui
    const string& GetNgayGui() const;
    void SetNgayGui(const string& ngayGuiMoi);

    // Trang thai
    const string& GetTrangThai() const;
    void SetTrangThai(const string& trangThaiMoi);

    // Ma nguoi gui
    const string& GetMaNguoiGui() const;
    void SetMaNguoiGui(const string& maNguoiGuiMoi);

    // Ma nguoi nhan
    const string& GetMaNguoiNhan() const;
    void SetMaNguoiNhan(const string& maNguoiNhanMoi);

    // Ma nhan vien tiep nhan
    const string& GetMaNhanVienTiepNhan() const;
    void SetMaNhanVienTiepNhan(const string& maNhanVienTiepNhanMoi);

    // Ma chuyen
    const string& GetMaChuyen() const;
    void SetMaChuyen(const string& maChuyenMoi);

    // Thoi gian giao du kien
    const string& GetThoiGianGiaoDuKien() const;
    void SetThoiGianGiaoDuKien(const string& thoiGianGiaoDuKienMoi);

    // Phi dich vu
    double GetPhiDichVu() const;
    void SetPhiDichVu(const double& phiDichVuMoi);

    // Tong phi
    double GetTongPhi() const;
    void SetTongPhi(const double& tongPhiMoi);

};

#endif
