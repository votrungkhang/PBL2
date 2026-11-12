#ifndef KHACHHANGSERVICE_H
#define KHACHHANGSERVICE_H

#include <string>
#include <vector>

class IKHACHHANGREPOSITORY;

struct ThongTinKhachHang {
    std::string maKhachHang;
    std::string hoTen;
    std::string sdt;
    std::string diaChi;
};

enum class KetQuaThemKhachHang {
    THANH_CONG,
    MA_TRONG,
    LOI_LUU_TRU
};

enum class KetQuaCapNhatKhachHang {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOI_LUU_TRU
};

enum class KetQuaXuLyKhachHang {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOI_LUU_TRU
};

class KHACHHANGSERVICE {
private:
    IKHACHHANGREPOSITORY& repository;
    int so_luong_khach_hang_hom_nay;
    std::string ngay_cua_bo_dem;

public:
    explicit KHACHHANGSERVICE(IKHACHHANGREPOSITORY& repository);

    KetQuaThemKhachHang themKhachHang(ThongTinKhachHang& thongTin);
    bool timKhachHangTheoMa(
        const std::string& maKhachHang,
        ThongTinKhachHang& ketQua) const;
    KetQuaCapNhatKhachHang capNhatKhachHang(
        const std::string& maKhachHang,
        const ThongTinKhachHang& thongTin);
    KetQuaXuLyKhachHang xoaKhachHang(const std::string& maKhachHang);
    std::vector<ThongTinKhachHang> layDanhSachKhachHang() const;

    static std::string layNgayHienTai();
    int GetSoLuongKhachHangHomNay() const;
    void SetSoLuongKhachHangHomNay(int soLuongMoi);
};

#endif