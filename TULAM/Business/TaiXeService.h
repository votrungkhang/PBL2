#ifndef TAIXESERVICE_H
#define TAIXESERVICE_H

#include <cstddef>
#include <string>
#include <vector>

class ITAIXEREPOSITORY;

struct ThongTinTaiXe {
    std::string maTaiXe;
    std::string hoTen;
    std::string sdt;
    std::string bangLai;
};

enum class KetQuaThemTaiXe {
    THANH_CONG,
    MA_TRONG,
    LOI_LUU_TRU
};

enum class KetQuaCapNhatTaiXe {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOI_LUU_TRU
};

enum class KetQuaXuLyTaiXe {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOI_LUU_TRU
};

class TAIXESERVICE {
private:
    ITAIXEREPOSITORY& repository;
    std::size_t soThuTuTaiXeDaTao;

public:
    explicit TAIXESERVICE(ITAIXEREPOSITORY& repository);

    KetQuaThemTaiXe themTaiXe(ThongTinTaiXe& thongTin);
    bool timTaiXeTheoMa(
        const std::string& maTaiXe,
        ThongTinTaiXe& ketQua) const;
    KetQuaCapNhatTaiXe capNhatTaiXe(
        const std::string& maTaiXe,
        const ThongTinTaiXe& thongTin);
    KetQuaXuLyTaiXe xoaTaiXe(const std::string& maTaiXe);
    std::vector<ThongTinTaiXe> layDanhSachTaiXe() const;
};

#endif
