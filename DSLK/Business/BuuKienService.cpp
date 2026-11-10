#include "BuuKienService.h"

#include <memory>
#include <utility>
#include "../Domain/BuuKienBinhThuong.h"
#include "../Domain/BuuKienHoaToc.h"
#include "../Domain/BuuKienNhanh.h"

BuuKienService::BuuKienService(IBuuKienRepository& repository)
    : repository(repository) {}

KetQuaThemBuuKien BuuKienService::themBuuKien(
    const std::string& maBuuKien,
    int loaiBuuKien) {
    if (maBuuKien.empty()) {
        return KetQuaThemBuuKien::MA_TRONG;
    }
    if (repository.contains(maBuuKien)) {
        return KetQuaThemBuuKien::MA_DA_TON_TAI;
    }

    std::unique_ptr<BuuKien> buuKien;
    switch (loaiBuuKien) {
    case 1:
        buuKien.reset(new BuuKienBinhThuong(maBuuKien));
        break;
    case 2:
        buuKien.reset(new BuuKienHoaToc(maBuuKien));
        break;
    case 3:
        buuKien.reset(new BuuKienNhanh(maBuuKien));
        break;
    default:
        return KetQuaThemBuuKien::LOAI_KHONG_HOP_LE;
    }

    return repository.add(std::move(buuKien))
        ? KetQuaThemBuuKien::THANH_CONG
        : KetQuaThemBuuKien::LOI_LUU_TRU;
}

std::vector<const BuuKien*> BuuKienService::layDanhSachBuuKien() const {
    return repository.getAll();
}
