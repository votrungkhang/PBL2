#include "KhachhangService.h"

#include <ctime>
#include <iomanip>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "IKhachHangRepository.h"

namespace {
void ganThongTin(
    KHACHHANG& khachHang,
    const ThongTinKhachHang& thongTin) {
    khachHang.SetMaKhachHang(thongTin.maKhachHang);
    khachHang.SetHoTen(thongTin.hoTen);
    khachHang.SetSdt(thongTin.sdt);
    khachHang.SetDiaChi(thongTin.diaChi);
}

std::string taoMaKhachHangMoi(
    const std::string& ngay,
    std::size_t soThuTu) {
    std::ostringstream maKhachHang;
    maKhachHang << "KH" << ngay
                << std::setw(4) << std::setfill('0') << soThuTu;
    return maKhachHang.str();
}

ThongTinKhachHang chuyenSangThongTin(const KHACHHANG& khachHang) {
    ThongTinKhachHang thongTin;
    thongTin.maKhachHang = khachHang.GetMaKhachHang();
    thongTin.hoTen = khachHang.GetHoTen();
    thongTin.sdt = khachHang.GetSdt();
    thongTin.diaChi = khachHang.GetDiaChi();
    return thongTin;
}
}

KHACHHANGSERVICE::KHACHHANGSERVICE(
    IKHACHHANGREPOSITORY& repository)
    : repository(repository),
      so_luong_khach_hang_hom_nay(0),
      ngay_cua_bo_dem(layNgayHienTai()) {}

KetQuaThemKhachHang KHACHHANGSERVICE::themKhachHang(
    ThongTinKhachHang& thongTin) {
    const std::string ngayHienTai = layNgayHienTai();
    if (ngay_cua_bo_dem != ngayHienTai) {
        so_luong_khach_hang_hom_nay = 0;
        ngay_cua_bo_dem = ngayHienTai;
    }

    std::size_t soThuTu =
        static_cast<std::size_t>(so_luong_khach_hang_hom_nay) + 1;
    std::string maMoi = taoMaKhachHangMoi(ngayHienTai, soThuTu);
    if (maMoi.empty()) {
        return KetQuaThemKhachHang::MA_TRONG;
    }
    while (repository.contains(maMoi)) {
        maMoi = taoMaKhachHangMoi(ngayHienTai, ++soThuTu);
    }

    std::unique_ptr<KHACHHANG> khachHang =
        std::make_unique<KHACHHANG>();
    ganThongTin(*khachHang, thongTin);
    khachHang->SetMaKhachHang(maMoi);

    if (!repository.add(std::move(khachHang))) {
        return KetQuaThemKhachHang::LOI_LUU_TRU;
    }

    thongTin.maKhachHang = maMoi;
    so_luong_khach_hang_hom_nay = static_cast<int>(soThuTu);
    return KetQuaThemKhachHang::THANH_CONG;
}

bool KHACHHANGSERVICE::timKhachHangTheoMa(
    const std::string& maKhachHang,
    ThongTinKhachHang& ketQua) const {
    if (maKhachHang.empty()) {
        return false;
    }

    const KHACHHANG* khachHang =
        repository.findByMaKhachHang(maKhachHang);
    if (khachHang == nullptr) {
        return false;
    }

    ketQua = chuyenSangThongTin(*khachHang);
    return true;
}

KetQuaCapNhatKhachHang KHACHHANGSERVICE::capNhatKhachHang(
    const std::string& maKhachHang,
    const ThongTinKhachHang& thongTin) {
    if (repository.findByMaKhachHang(maKhachHang) == nullptr) {
        return KetQuaCapNhatKhachHang::KHONG_TIM_THAY;
    }

    ThongTinKhachHang thongTinCapNhat = thongTin;
    thongTinCapNhat.maKhachHang = maKhachHang;
    std::unique_ptr<KHACHHANG> khachHang =
        std::make_unique<KHACHHANG>();
    ganThongTin(*khachHang, thongTinCapNhat);

    return repository.update(maKhachHang, std::move(khachHang))
        ? KetQuaCapNhatKhachHang::THANH_CONG
        : KetQuaCapNhatKhachHang::LOI_LUU_TRU;
}

KetQuaXuLyKhachHang KHACHHANGSERVICE::xoaKhachHang(
    const std::string& maKhachHang) {
    if (repository.findByMaKhachHang(maKhachHang) == nullptr) {
        return KetQuaXuLyKhachHang::KHONG_TIM_THAY;
    }

    return repository.remove(maKhachHang)
        ? KetQuaXuLyKhachHang::THANH_CONG
        : KetQuaXuLyKhachHang::LOI_LUU_TRU;
}

std::vector<ThongTinKhachHang>
KHACHHANGSERVICE::layDanhSachKhachHang() const {
    const std::vector<const KHACHHANG*> khachHangTrongKho =
        repository.getAll();
    std::vector<ThongTinKhachHang> danhSach;
    danhSach.reserve(khachHangTrongKho.size());

    for (const KHACHHANG* khachHang : khachHangTrongKho) {
        danhSach.push_back(chuyenSangThongTin(*khachHang));
    }

    return danhSach;
}

std::string KHACHHANGSERVICE::layNgayHienTai() {
    const std::time_t now = std::time(nullptr);
    const std::tm* current = std::localtime(&now);
    if (current == nullptr) {
        throw std::runtime_error("Khong lay duoc ngay he thong");
    }

    std::ostringstream ngay;
    ngay << std::setw(2) << std::setfill('0') << current->tm_mday
         << std::setw(2) << std::setfill('0') << (current->tm_mon + 1)
         << (current->tm_year + 1900);
    return ngay.str();
}

int KHACHHANGSERVICE::GetSoLuongKhachHangHomNay() const {
    return so_luong_khach_hang_hom_nay;
}

void KHACHHANGSERVICE::SetSoLuongKhachHangHomNay(int soLuongMoi) {
    so_luong_khach_hang_hom_nay = soLuongMoi;
}