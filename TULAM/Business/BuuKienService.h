#ifndef BUUKIENSERVICE_H
#define BUUKIENSERVICE_H

#include <string>
#include <vector>
#include "../Domain/Enums.h"

class IBUUKIENREPOSITORY;

struct ThongTinBuuKien {
    std::string maBuuKien;
    std::string loaiBuuKien;
    double trongLuong = 0;
    std::string diaChiGui;
    std::string diaChiNhan;
    std::string ngayGui;
    std::string trangThai;
    std::string maNguoiGui;
    std::string maNguoiNhan;
    std::string maNhanVienTiepNhan;
    std::string maChuyen;
    double phiDichVu = 0;
    std::string thoiGianGiaoDuKien;
    double tongPhi = 0;
};

enum class KetQuaThemBuuKien {
    THANH_CONG,
    MA_TRONG,
    MA_DA_TON_TAI,
    LOAI_KHONG_HOP_LE,
    TRANG_THAI_KHONG_HOP_LE,
    LOI_LUU_TRU
};

enum class KetQuaCapNhatBuuKien {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOAI_KHONG_HOP_LE,
    TRANG_THAI_KHONG_HOP_LE,
    LOI_LUU_TRU
};

enum class KetQuaXuLyBuuKien {
    THANH_CONG,
    KHONG_TIM_THAY,
    DA_HUY,
    LOI_LUU_TRU
};

class BUUKIENSERVICE {
private:
    IBUUKIENREPOSITORY& repository;
    int so_luong_buu_kien_hom_nay;
    std::string ngay_cua_bo_dem;

public:
    BUUKIENSERVICE(IBUUKIENREPOSITORY& repository);

    KetQuaThemBuuKien themBuuKien(ThongTinBuuKien& thongTin);
    bool timBuuKienTheoMa(
        const std::string& maBuuKien,
        ThongTinBuuKien& ketQua) const;
    KetQuaCapNhatBuuKien capNhatBuuKien(
        const std::string& maBuuKien,
        const ThongTinBuuKien& thongTin);
    KetQuaXuLyBuuKien huyBuuKien(const std::string& maBuuKien);
    KetQuaXuLyBuuKien xoaBuuKien(const std::string& maBuuKien);
    std::vector<ThongTinBuuKien> layDanhSachBuuKien() const;
    static std::string layNgayHienTai();
    int GetSoLuongBuuKienHomNay();
    void SetSoLuongBuuKienHomNay(const int&);
};

#endif
