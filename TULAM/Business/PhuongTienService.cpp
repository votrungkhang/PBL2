#include "PhuongTienService.h"

#include <iomanip>
#include <memory>
#include <sstream>
#include <utility>

#include "IPhuongTienRepository.h"

namespace {
std::string taoMaPhuongTienMoi(std::size_t soThuTu) {
    std::ostringstream maPhuongTien;
    maPhuongTien << "PT"
                 << std::setw(4) << std::setfill('0') << soThuTu;
    return maPhuongTien.str();
}

void ganThongTin(
    PHUONGTIEN& phuongTien,
    const ThongTinPhuongTien& thongTin) {
    phuongTien.SetMaPhuongTien(thongTin.maPhuongTien);
    phuongTien.SetBienSo(thongTin.bienSo);
    phuongTien.SetLoaiXe(thongTin.loaiXe);
    phuongTien.SetTaiTrongToiDa(thongTin.taiTrongToiDa);
    phuongTien.SetTrangThai(thongTin.trangThai);
}

ThongTinPhuongTien chuyenSangThongTin(const PHUONGTIEN& phuongTien) {
    ThongTinPhuongTien thongTin;
    thongTin.maPhuongTien = phuongTien.GetMaPhuongTien();
    thongTin.bienSo = phuongTien.GetBienSo();
    thongTin.loaiXe = phuongTien.GetLoaiXe();
    thongTin.taiTrongToiDa = phuongTien.GetTaiTrongToiDa();
    thongTin.trangThai = phuongTien.GetTrangThai();
    return thongTin;
}
}

PHUONGTIENSERVICE::PHUONGTIENSERVICE(
    IPHUONGTIENREPOSITORY& repository)
    : repository(repository), soThuTuPhuongTienDaTao(0) {}

KetQuaThemPhuongTien PHUONGTIENSERVICE::themPhuongTien(
    ThongTinPhuongTien& thongTin) {
    std::size_t soThuTu = soThuTuPhuongTienDaTao + 1;
    std::string maMoi = taoMaPhuongTienMoi(soThuTu);
    if (maMoi.empty()) {
        return KetQuaThemPhuongTien::MA_TRONG;
    }

    while (repository.contains(maMoi)) {
        maMoi = taoMaPhuongTienMoi(++soThuTu);
    }

    ThongTinPhuongTien thongTinMoi = thongTin;
    thongTinMoi.maPhuongTien = maMoi;
    std::unique_ptr<PHUONGTIEN> phuongTien =
        std::make_unique<PHUONGTIEN>();
    ganThongTin(*phuongTien, thongTinMoi);

    if (!repository.add(std::move(phuongTien))) {
        return KetQuaThemPhuongTien::LOI_LUU_TRU;
    }

    thongTin.maPhuongTien = maMoi;
    soThuTuPhuongTienDaTao = soThuTu;
    return KetQuaThemPhuongTien::THANH_CONG;
}

bool PHUONGTIENSERVICE::timPhuongTienTheoMa(
    const std::string& maPhuongTien,
    ThongTinPhuongTien& ketQua) const {
    if (maPhuongTien.empty()) {
        return false;
    }

    const PHUONGTIEN* phuongTien =
        repository.findByMaPhuongTien(maPhuongTien);
    if (phuongTien == nullptr) {
        return false;
    }

    ketQua = chuyenSangThongTin(*phuongTien);
    return true;
}

KetQuaCapNhatPhuongTien PHUONGTIENSERVICE::capNhatPhuongTien(
    const std::string& maPhuongTien,
    const ThongTinPhuongTien& thongTin) {
    if (repository.findByMaPhuongTien(maPhuongTien) == nullptr) {
        return KetQuaCapNhatPhuongTien::KHONG_TIM_THAY;
    }

    ThongTinPhuongTien thongTinCapNhat = thongTin;
    thongTinCapNhat.maPhuongTien = maPhuongTien;
    std::unique_ptr<PHUONGTIEN> phuongTien =
        std::make_unique<PHUONGTIEN>();
    ganThongTin(*phuongTien, thongTinCapNhat);

    return repository.update(maPhuongTien, std::move(phuongTien))
        ? KetQuaCapNhatPhuongTien::THANH_CONG
        : KetQuaCapNhatPhuongTien::LOI_LUU_TRU;
}

KetQuaXuLyPhuongTien PHUONGTIENSERVICE::xoaPhuongTien(
    const std::string& maPhuongTien) {
    if (repository.findByMaPhuongTien(maPhuongTien) == nullptr) {
        return KetQuaXuLyPhuongTien::KHONG_TIM_THAY;
    }

    return repository.remove(maPhuongTien)
        ? KetQuaXuLyPhuongTien::THANH_CONG
        : KetQuaXuLyPhuongTien::LOI_LUU_TRU;
}

std::vector<ThongTinPhuongTien>
PHUONGTIENSERVICE::layDanhSachPhuongTien() const {
    const std::vector<const PHUONGTIEN*> phuongTienTrongKho =
        repository.getAll();
    std::vector<ThongTinPhuongTien> danhSach;
    danhSach.reserve(phuongTienTrongKho.size());

    for (const PHUONGTIEN* phuongTien : phuongTienTrongKho) {
        danhSach.push_back(chuyenSangThongTin(*phuongTien));
    }

    return danhSach;
}
