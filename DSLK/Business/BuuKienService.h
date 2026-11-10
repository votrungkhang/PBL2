#ifndef BUUKIENSERVICE_H
#define BUUKIENSERVICE_H

#include <string>
#include <vector>
#include "../DataAccess/IBuuKienRepository.h"

enum class KetQuaThemBuuKien {
    THANH_CONG,
    MA_TRONG,
    MA_DA_TON_TAI,
    LOAI_KHONG_HOP_LE,
    LOI_LUU_TRU
};

class BuuKienService {
private:
    IBuuKienRepository& repository;

public:
    explicit BuuKienService(IBuuKienRepository& repository);

    KetQuaThemBuuKien themBuuKien(
        const std::string& maBuuKien,
        int loaiBuuKien);
    std::vector<const BuuKien*> layDanhSachBuuKien() const;
};

#endif
