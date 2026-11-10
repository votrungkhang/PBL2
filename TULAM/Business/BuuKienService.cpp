#include "BuuKienService.h"

#include <memory>
#include <utility>
#include "IBuuKienRepository.h"
#include "../Domain/BuuKienBinhThuong.h"
#include "../Domain/BuuKienHoaToc.h"
#include "../Domain/BuuKienNhanh.h"

namespace {
unique_ptr<BuuKien> taoBuuKien(LoaiBuuKien loai) {
    switch (loai) {
    case LoaiBuuKien::BINH_THUONG:
        return make_unique<BuuKienBinhThuong>();
    case LoaiBuuKien::HOA_TOC:
        return make_unique<BuuKienHoaToc>();
    case LoaiBuuKien::NHANH:
        return make_unique<BuuKienNhanh>();
    default:
        return nullptr;
    }
}

void ganThongTin(BuuKien& buuKien, const ThongTinBuuKien& thongTin) {
    buuKien.setMaBuuKien(thongTin.maBuuKien);
    buuKien.setTrongLuong(thongTin.trongLuong);
    buuKien.setDiaChiGui(thongTin.diaChiGui);
    buuKien.setDiaChiNhan(thongTin.diaChiNhan);
    buuKien.setNgayGui(thongTin.ngayGui);
    buuKien.setTrangThai(thongTin.trangThai);
    buuKien.setMaNguoiGui(thongTin.maNguoiGui);
    buuKien.setMaNguoiNhan(thongTin.maNguoiNhan);
    buuKien.setMaNhanVienTiepNhan(thongTin.maNhanVienTiepNhan);
    buuKien.setMaChuyen(thongTin.maChuyen);
    buuKien.setPhiDichVu(thongTin.phiDichVu);
    buuKien.setThoiGianGiaoDuKien(thongTin.thoiGianGiaoDuKien);
    buuKien.setTongPhi(thongTin.tongPhi);
}

ThongTinBuuKien chuyenSangThongTin(const BuuKien& buuKien) {
    ThongTinBuuKien thongTin;
    thongTin.maBuuKien = buuKien.getMaBuuKien();
    thongTin.loaiBuuKien = buuKien.getLoaiBuuKien();
    thongTin.trongLuong = buuKien.getTrongLuong();
    thongTin.diaChiGui = buuKien.getDiaChiGui();
    thongTin.diaChiNhan = buuKien.getDiaChiNhan();
    thongTin.ngayGui = buuKien.getNgayGui();
    thongTin.trangThai = buuKien.getTrangThai();
    thongTin.maNguoiGui = buuKien.getMaNguoiGui();
    thongTin.maNguoiNhan = buuKien.getMaNguoiNhan();
    thongTin.maNhanVienTiepNhan = buuKien.getMaNhanVienTiepNhan();
    thongTin.maChuyen = buuKien.getMaChuyen();
    thongTin.phiDichVu = buuKien.getPhiDichVu();
    thongTin.thoiGianGiaoDuKien = buuKien.getThoiGianGiaoDuKien();
    thongTin.tongPhi = buuKien.getTongPhi();
    return thongTin;
}
}

BuuKienService::BuuKienService(IBuuKienRepository& repository)
    : repository(repository) {}

KetQuaThemBuuKien BuuKienService::themBuuKien(
    const ThongTinBuuKien& thongTin) {
    if (thongTin.maBuuKien.empty()) {
        return KetQuaThemBuuKien::MA_TRONG;
    }
    if (repository.contains(thongTin.maBuuKien)) {
        return KetQuaThemBuuKien::MA_DA_TON_TAI;
    }

    unique_ptr<BuuKien> buuKien = taoBuuKien(thongTin.loaiBuuKien);
    if (!buuKien) {
        return KetQuaThemBuuKien::LOAI_KHONG_HOP_LE;
    }

    ganThongTin(*buuKien, thongTin);

    return repository.add(move(buuKien))
        ? KetQuaThemBuuKien::THANH_CONG
        : KetQuaThemBuuKien::LOI_LUU_TRU;
}

bool BuuKienService::timBuuKienTheoMa(
    const string& maBuuKien,
    ThongTinBuuKien& ketQua) const {
    if (maBuuKien.empty()) {
        return false;
    }

    const BuuKien* buuKien = repository.findByMaBuuKien(maBuuKien);
    if (buuKien == nullptr) {
        return false;
    }

    ketQua = chuyenSangThongTin(*buuKien);
    return true;
}

KetQuaCapNhatBuuKien BuuKienService::capNhatBuuKien(
    const string& maBuuKien,
    const ThongTinBuuKien& thongTin) {
    if (repository.findByMaBuuKien(maBuuKien) == nullptr) {
        return KetQuaCapNhatBuuKien::KHONG_TIM_THAY;
    }

    unique_ptr<BuuKien> buuKien = taoBuuKien(thongTin.loaiBuuKien);
    if (!buuKien) {
        return KetQuaCapNhatBuuKien::LOAI_KHONG_HOP_LE;
    }

    ThongTinBuuKien thongTinCapNhat = thongTin;
    thongTinCapNhat.maBuuKien = maBuuKien;
    ganThongTin(*buuKien, thongTinCapNhat);

    return repository.update(maBuuKien, move(buuKien))
        ? KetQuaCapNhatBuuKien::THANH_CONG
        : KetQuaCapNhatBuuKien::LOI_LUU_TRU;
}

KetQuaXuLyBuuKien BuuKienService::huyBuuKien(
    const string& maBuuKien) {
    const BuuKien* buuKien = repository.findByMaBuuKien(maBuuKien);
    if (buuKien == nullptr) {
        return KetQuaXuLyBuuKien::KHONG_TIM_THAY;
    }
    if (buuKien->getTrangThai() == "DA_HUY") {
        return KetQuaXuLyBuuKien::DA_HUY;
    }

    return repository.updateTrangThai(maBuuKien, "DA_HUY")
        ? KetQuaXuLyBuuKien::THANH_CONG
        : KetQuaXuLyBuuKien::LOI_LUU_TRU;
}

KetQuaXuLyBuuKien BuuKienService::xoaBuuKien(
    const string& maBuuKien) {
    if (repository.findByMaBuuKien(maBuuKien) == nullptr) {
        return KetQuaXuLyBuuKien::KHONG_TIM_THAY;
    }

    return repository.remove(maBuuKien)
        ? KetQuaXuLyBuuKien::THANH_CONG
        : KetQuaXuLyBuuKien::LOI_LUU_TRU;
}

vector<ThongTinBuuKien> BuuKienService::layDanhSachBuuKien() const {
    const vector<const BuuKien*> buuKienTrongKho = repository.getAll();
    vector<ThongTinBuuKien> danhSach;
    danhSach.reserve(buuKienTrongKho.size());

    for (const BuuKien* buuKien : buuKienTrongKho) {
        danhSach.push_back(chuyenSangThongTin(*buuKien));
    }

    return danhSach;
}
