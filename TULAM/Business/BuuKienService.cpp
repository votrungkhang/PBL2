#include "BuuKienService.h"

#include <memory>
#include <utility>
#include "IBuuKienRepository.h"
#include "../Domain/BuuKienBinhThuong.h"
#include "../Domain/BuuKienHoaToc.h"
#include "../Domain/BuuKienNhanh.h"

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

    unique_ptr<BuuKien> buuKien;
    switch (thongTin.loaiBuuKien) {
    case LoaiBuuKien::BINH_THUONG:
        buuKien=make_unique<BuuKienBinhThuong>();
        break;
    case LoaiBuuKien::HOA_TOC:
        buuKien=make_unique<BuuKienHoaToc>();
        break;
    case LoaiBuuKien::NHANH:
        buuKien=make_unique<BuuKienNhanh>();
        break;
    default:
        return KetQuaThemBuuKien::LOAI_KHONG_HOP_LE;
    }

    buuKien->setMaBuuKien(thongTin.maBuuKien);
    buuKien->setTrongLuong(thongTin.trongLuong);
    buuKien->setDiaChiGui(thongTin.diaChiGui);
    buuKien->setDiaChiNhan(thongTin.diaChiNhan);
    buuKien->setNgayGui(thongTin.ngayGui);
    buuKien->setTrangThai(thongTin.trangThai);
    buuKien->setMaNguoiGui(thongTin.maNguoiGui);
    buuKien->setMaNguoiNhan(thongTin.maNguoiNhan);
    buuKien->setMaNhanVienTiepNhan(thongTin.maNhanVienTiepNhan);
    buuKien->setMaChuyen(thongTin.maChuyen);
    buuKien->setPhiDichVu(thongTin.phiDichVu);
    buuKien->setThoiGianGiaoDuKien(thongTin.thoiGianGiaoDuKien);
    buuKien->setTongPhi(thongTin.tongPhi);

    return repository.add(move(buuKien))
        ? KetQuaThemBuuKien::THANH_CONG
        : KetQuaThemBuuKien::LOI_LUU_TRU;
}

vector<ThongTinBuuKien> BuuKienService::layDanhSachBuuKien() const {
    const vector<const BuuKien*> buuKienTrongKho = repository.getAll();
    vector<ThongTinBuuKien> danhSach;
    danhSach.reserve(buuKienTrongKho.size());

    for (const BuuKien* buuKien : buuKienTrongKho) {
        ThongTinBuuKien thongTin;
        thongTin.maBuuKien = buuKien->getMaBuuKien();
        thongTin.loaiBuuKien = buuKien->getLoaiBuuKien();
        thongTin.trongLuong = buuKien->getTrongLuong();
        thongTin.diaChiGui = buuKien->getDiaChiGui();
        thongTin.diaChiNhan = buuKien->getDiaChiNhan();
        thongTin.ngayGui = buuKien->getNgayGui();
        thongTin.trangThai = buuKien->getTrangThai();
        thongTin.maNguoiGui = buuKien->getMaNguoiGui();
        thongTin.maNguoiNhan = buuKien->getMaNguoiNhan();
        thongTin.maNhanVienTiepNhan = buuKien->getMaNhanVienTiepNhan();
        thongTin.maChuyen = buuKien->getMaChuyen();
        thongTin.phiDichVu = buuKien->getPhiDichVu();
        thongTin.thoiGianGiaoDuKien = buuKien->getThoiGianGiaoDuKien();
        thongTin.tongPhi = buuKien->getTongPhi();
        danhSach.push_back(thongTin);
    }

    return danhSach;
}
