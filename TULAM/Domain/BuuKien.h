#ifndef BUUKIEN_H
#define BUUKIEN_H

#include <string>
using namespace std;
#include "Enums.h"

class BuuKien {
protected:
    LoaiBuuKien loaiBuuKien;
    string maBuuKien;
    double trongLuong;
    string diaChiGui;
    string diaChiNhan;
    string ngayGui;
    string trangThai;
    string maNguoiGui;
    string maNguoiNhan;
    string maNhanVienTiepNhan;
    string maChuyen;
    string thoiGianGiaoDuKien;
    double phiDichVu;
    double tongphi;

public:
    virtual ~BuuKien() = default;

    BuuKien(
        const string& maBuuKien = "",
        LoaiBuuKien loaiBuuKien = LoaiBuuKien::CHUA_XAC_DINH,
        double trongLuong = 0,
        const string& diaChiGui = "",
        const string& diaChiNhan = "",
        const string& ngayGui = "",
        const string& trangThai = "",
        const string& maNguoiGui = "",
        const string& maNguoiNhan = "",
        const string& maNhanVienTiepNhan = "",
        const string& maChuyen = "",
        const string& thoiGianGiaoDuKien = "",
        double phiDichVu = 0,
        double tongphi = 0);

    // Loai buu kien
    LoaiBuuKien getLoaiBuuKien() const;
    void setLoaiBuuKien(LoaiBuuKien loaiBuuKienMoi);

    // Ma buu kien
    const string& getMaBuuKien() const;
    void setMaBuuKien(const string& maBuuKienMoi);

    // Trong luong
    double getTrongLuong() const;
    void setTrongLuong(double trongLuongMoi);

    // Dia chi gui
    const string& getDiaChiGui() const;
    void setDiaChiGui(const string& diaChiGuiMoi);

    // Dia chi nhan
    const string& getDiaChiNhan() const;
    void setDiaChiNhan(const string& diaChiNhanMoi);

    // Ngay gui
    const string& getNgayGui() const;
    void setNgayGui(const string& ngayGuiMoi);

    // Trang thai
    const string& getTrangThai() const;
    void setTrangThai(const string& trangThaiMoi);

    // Ma nguoi gui
    const string& getMaNguoiGui() const;
    void setMaNguoiGui(const string& maNguoiGuiMoi);

    // Ma nguoi nhan
    const string& getMaNguoiNhan() const;
    void setMaNguoiNhan(const string& maNguoiNhanMoi);

    // Ma nhan vien tiep nhan
    const string& getMaNhanVienTiepNhan() const;
    void setMaNhanVienTiepNhan(const string& maNhanVienTiepNhanMoi);

    // Ma chuyen
    const string& getMaChuyen() const;
    void setMaChuyen(const string& maChuyenMoi);

    // Thoi gian giao du kien
    const string& getThoiGianGiaoDuKien() const;
    void setThoiGianGiaoDuKien(const string& thoiGianGiaoDuKienMoi);

    // Phi dich vu
    double getPhiDichVu() const;
    void setPhiDichVu(double phiDichVuMoi);

    // Tong phi
    double getTongPhi() const;
    void setTongPhi(double tongPhiMoi);


};

#endif
