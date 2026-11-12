#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "../Business/BuuKienService.h"
#include "../Business/KhachhangService.h"
#include "../Business/NhanVienService.h"
#include "../Business/TaiXeService.h"
#include "../Business/PhuongTienService.h"

class CONSOLEUI {
private:
    BUUKIENSERVICE& buuKienService;
    KHACHHANGSERVICE& khachHangService;
    NHANVIENSERVICE& nhanVienService;
    TAIXESERVICE& taiXeService;
    PHUONGTIENSERVICE& phuongTienService;

    void menuQuanLyBuuKien();
    void menuTimKiemVaThongKe();
    void menuQuanLyKhachHang();
    void menuQuanLyNhanVien();
    void menuQuanLyTaiXe();
    void menuQuanLyPhuongTien();
    void themBuuKien();
    void timKiemBuuKien() const;
    void capNhatBuuKien();
    void huyBuuKien();
    void xoaBuuKien();
    void hienThiDanhSach() const;
    void locTheoTrangThai() const;
    void locTheoLoai() const;
    void thongKe() const;
    void themKhachHang();
    void timKiemKhachHang() const;
    void capNhatKhachHang();
    void xoaKhachHang();
    void hienThiDanhSachKhachHang() const;
    void themNhanVien();
    void timKiemNhanVien() const;
    void capNhatNhanVien();
    void xoaNhanVien();
    void hienThiDanhSachNhanVien() const;
    void themTaiXe();
    void timKiemTaiXe() const;
    void capNhatTaiXe();
    void xoaTaiXe();
    void hienThiDanhSachTaiXe() const;
    void themPhuongTien();
    void timKiemPhuongTien() const;
    void capNhatPhuongTien();
    void xoaPhuongTien();
    void hienThiDanhSachPhuongTien() const;

public:
    CONSOLEUI(
        BUUKIENSERVICE& buuKienService,
        KHACHHANGSERVICE& khachHangService,
        NHANVIENSERVICE& nhanVienService,
        TAIXESERVICE& taiXeService,
        PHUONGTIENSERVICE& phuongTienService);
    int run();
};

#endif
