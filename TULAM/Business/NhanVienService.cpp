#include "NhanVienService.h"

#include <iomanip>
#include <memory>
#include <sstream>
#include <utility>

#include "INhanVienRepository.h"

namespace {
std::string taoMaNhanVienMoi(std::size_t soThuTu) {
    std::ostringstream maNhanVien;
    maNhanVien << "NV"
               << std::setw(4) << std::setfill('0') << soThuTu;
    return maNhanVien.str();
}

void ganThongTin(
    NHANVIEN& nhanVien,
    const ThongTinNhanVien& thongTin) {
    nhanVien.SetMaNhanVien(thongTin.maNhanVien);
    nhanVien.SetHoTen(thongTin.hoTen);
    nhanVien.SetChucVu(thongTin.chucVu);
    nhanVien.SetSdt(thongTin.sdt);
}

ThongTinNhanVien chuyenSangThongTin(const NHANVIEN& nhanVien) {
    ThongTinNhanVien thongTin;
    thongTin.maNhanVien = nhanVien.GetMaNhanVien();
    thongTin.hoTen = nhanVien.GetHoTen();
    thongTin.chucVu = nhanVien.GetChucVu();
    thongTin.sdt = nhanVien.GetSdt();
    return thongTin;
}
}

NHANVIENSERVICE::NHANVIENSERVICE(
    INHANVIENREPOSITORY& repository)
    : repository(repository), soThuTuNhanVienDaTao(0) {}

KetQuaThemNhanVien NHANVIENSERVICE::themNhanVien(
    ThongTinNhanVien& thongTin) {
    std::size_t soThuTu = soThuTuNhanVienDaTao + 1;
    std::string maMoi = taoMaNhanVienMoi(soThuTu);
    if (maMoi.empty()) {
        return KetQuaThemNhanVien::MA_TRONG;
    }

    while (repository.contains(maMoi)) {
        maMoi = taoMaNhanVienMoi(++soThuTu);
    }

    std::unique_ptr<NHANVIEN> nhanVien = std::make_unique<NHANVIEN>();
    ThongTinNhanVien thongTinMoi = thongTin;
    thongTinMoi.maNhanVien = maMoi;
    ganThongTin(*nhanVien, thongTinMoi);

    if (!repository.add(std::move(nhanVien))) {
        return KetQuaThemNhanVien::LOI_LUU_TRU;
    }

    thongTin.maNhanVien = maMoi;
    soThuTuNhanVienDaTao = soThuTu;
    return KetQuaThemNhanVien::THANH_CONG;
}

bool NHANVIENSERVICE::timNhanVienTheoMa(
    const std::string& maNhanVien,
    ThongTinNhanVien& ketQua) const {
    if (maNhanVien.empty()) {
        return false;
    }

    const NHANVIEN* nhanVien = repository.findByMaNhanVien(maNhanVien);
    if (nhanVien == nullptr) {
        return false;
    }

    ketQua = chuyenSangThongTin(*nhanVien);
    return true;
}

KetQuaCapNhatNhanVien NHANVIENSERVICE::capNhatNhanVien(
    const std::string& maNhanVien,
    const ThongTinNhanVien& thongTin) {
    if (repository.findByMaNhanVien(maNhanVien) == nullptr) {
        return KetQuaCapNhatNhanVien::KHONG_TIM_THAY;
    }

    ThongTinNhanVien thongTinCapNhat = thongTin;
    thongTinCapNhat.maNhanVien = maNhanVien;
    std::unique_ptr<NHANVIEN> nhanVien = std::make_unique<NHANVIEN>();
    ganThongTin(*nhanVien, thongTinCapNhat);

    return repository.update(maNhanVien, std::move(nhanVien))
        ? KetQuaCapNhatNhanVien::THANH_CONG
        : KetQuaCapNhatNhanVien::LOI_LUU_TRU;
}

KetQuaXuLyNhanVien NHANVIENSERVICE::xoaNhanVien(
    const std::string& maNhanVien) {
    if (repository.findByMaNhanVien(maNhanVien) == nullptr) {
        return KetQuaXuLyNhanVien::KHONG_TIM_THAY;
    }

    return repository.remove(maNhanVien)
        ? KetQuaXuLyNhanVien::THANH_CONG
        : KetQuaXuLyNhanVien::LOI_LUU_TRU;
}

std::vector<ThongTinNhanVien>
NHANVIENSERVICE::layDanhSachNhanVien() const {
    const std::vector<const NHANVIEN*> nhanVienTrongKho =
        repository.getAll();
    std::vector<ThongTinNhanVien> danhSach;
    danhSach.reserve(nhanVienTrongKho.size());

    for (const NHANVIEN* nhanVien : nhanVienTrongKho) {
        danhSach.push_back(chuyenSangThongTin(*nhanVien));
    }

    return danhSach;
}
