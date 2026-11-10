#ifndef BUUKIENSERVICE_H
#define BUUKIENSERVICE_H

#include <string>
#include <vector>
#include "../Domain/Enums.h"

class IBuuKienRepository;

struct ThongTinBuuKien {
    std::string maBuuKien;
    LoaiBuuKien loaiBuuKien = LoaiBuuKien::CHUA_XAC_DINH;
    double trongLuong = 0;
    std::string diaChiGui;
    std::string diaChiNhan;
    std::string ngayGui;
    std::string trangThai;
    std::string maNguoiGui;
    std::string maNguoiNhan;
    std::string maNhanVienTiepNhan;
    std::string maChuyen;
    double phiDichVu = 0;
    std::string thoiGianGiaoDuKien;
    double tongPhi = 0;
};

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
    BuuKienService(IBuuKienRepository& repository);

    KetQuaThemBuuKien themBuuKien(const ThongTinBuuKien& thongTin);
    std::vector<ThongTinBuuKien> layDanhSachBuuKien() const;
};

#endif
