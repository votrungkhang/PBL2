#include "TaiXeService.h"

#include <iomanip>
#include <memory>
#include <sstream>
#include <utility>

#include "ITaiXeRepository.h"

namespace {
std::string taoMaTaiXeMoi(std::size_t soThuTu) {
    std::ostringstream maTaiXe;
    maTaiXe << "TX"
            << std::setw(4) << std::setfill('0') << soThuTu;
    return maTaiXe.str();
}

void ganThongTin(TAIXE& taiXe, const ThongTinTaiXe& thongTin) {
    taiXe.SetMaTaiXe(thongTin.maTaiXe);
    taiXe.SetHoTen(thongTin.hoTen);
    taiXe.SetSdt(thongTin.sdt);
    taiXe.SetBangLai(thongTin.bangLai);
}

ThongTinTaiXe chuyenSangThongTin(const TAIXE& taiXe) {
    ThongTinTaiXe thongTin;
    thongTin.maTaiXe = taiXe.GetMaTaiXe();
    thongTin.hoTen = taiXe.GetHoTen();
    thongTin.sdt = taiXe.GetSdt();
    thongTin.bangLai = taiXe.GetBangLai();
    return thongTin;
}
}

TAIXESERVICE::TAIXESERVICE(ITAIXEREPOSITORY& repository)
    : repository(repository), soThuTuTaiXeDaTao(0) {}

KetQuaThemTaiXe TAIXESERVICE::themTaiXe(ThongTinTaiXe& thongTin) {
    std::size_t soThuTu = soThuTuTaiXeDaTao + 1;
    std::string maMoi = taoMaTaiXeMoi(soThuTu);
    if (maMoi.empty()) {
        return KetQuaThemTaiXe::MA_TRONG;
    }

    while (repository.contains(maMoi)) {
        maMoi = taoMaTaiXeMoi(++soThuTu);
    }

    ThongTinTaiXe thongTinMoi = thongTin;
    thongTinMoi.maTaiXe = maMoi;
    std::unique_ptr<TAIXE> taiXe = std::make_unique<TAIXE>();
    ganThongTin(*taiXe, thongTinMoi);

    if (!repository.add(std::move(taiXe))) {
        return KetQuaThemTaiXe::LOI_LUU_TRU;
    }

    thongTin.maTaiXe = maMoi;
    soThuTuTaiXeDaTao = soThuTu;
    return KetQuaThemTaiXe::THANH_CONG;
}

bool TAIXESERVICE::timTaiXeTheoMa(
    const std::string& maTaiXe,
    ThongTinTaiXe& ketQua) const {
    if (maTaiXe.empty()) {
        return false;
    }

    const TAIXE* taiXe = repository.findByMaTaiXe(maTaiXe);
    if (taiXe == nullptr) {
        return false;
    }

    ketQua = chuyenSangThongTin(*taiXe);
    return true;
}

KetQuaCapNhatTaiXe TAIXESERVICE::capNhatTaiXe(
    const std::string& maTaiXe,
    const ThongTinTaiXe& thongTin) {
    if (repository.findByMaTaiXe(maTaiXe) == nullptr) {
        return KetQuaCapNhatTaiXe::KHONG_TIM_THAY;
    }

    ThongTinTaiXe thongTinCapNhat = thongTin;
    thongTinCapNhat.maTaiXe = maTaiXe;
    std::unique_ptr<TAIXE> taiXe = std::make_unique<TAIXE>();
    ganThongTin(*taiXe, thongTinCapNhat);

    return repository.update(maTaiXe, std::move(taiXe))
        ? KetQuaCapNhatTaiXe::THANH_CONG
        : KetQuaCapNhatTaiXe::LOI_LUU_TRU;
}

KetQuaXuLyTaiXe TAIXESERVICE::xoaTaiXe(const std::string& maTaiXe) {
    if (repository.findByMaTaiXe(maTaiXe) == nullptr) {
        return KetQuaXuLyTaiXe::KHONG_TIM_THAY;
    }

    return repository.remove(maTaiXe)
        ? KetQuaXuLyTaiXe::THANH_CONG
        : KetQuaXuLyTaiXe::LOI_LUU_TRU;
}

std::vector<ThongTinTaiXe> TAIXESERVICE::layDanhSachTaiXe() const {
    const std::vector<const TAIXE*> taiXeTrongKho = repository.getAll();
    std::vector<ThongTinTaiXe> danhSach;
    danhSach.reserve(taiXeTrongKho.size());

    for (const TAIXE* taiXe : taiXeTrongKho) {
        danhSach.push_back(chuyenSangThongTin(*taiXe));
    }

    return danhSach;
}
