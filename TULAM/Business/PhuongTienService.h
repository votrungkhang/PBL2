#ifndef PHUONGTIENSERVICE_H
#define PHUONGTIENSERVICE_H

#include <cstddef>
#include <string>
#include <vector>

class IPHUONGTIENREPOSITORY;

struct ThongTinPhuongTien {
    std::string maPhuongTien;
    std::string bienSo;
    std::string loaiXe;
    double taiTrongToiDa = 0.0;
    std::string trangThai;
};

enum class KetQuaThemPhuongTien {
    THANH_CONG,
    MA_TRONG,
    LOI_LUU_TRU
};

enum class KetQuaCapNhatPhuongTien {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOI_LUU_TRU
};

enum class KetQuaXuLyPhuongTien {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOI_LUU_TRU
};

class PHUONGTIENSERVICE {
private:
    IPHUONGTIENREPOSITORY& repository;
    std::size_t soThuTuPhuongTienDaTao;

public:
    explicit PHUONGTIENSERVICE(IPHUONGTIENREPOSITORY& repository);

    KetQuaThemPhuongTien themPhuongTien(ThongTinPhuongTien& thongTin);
    bool timPhuongTienTheoMa(
        const std::string& maPhuongTien,
        ThongTinPhuongTien& ketQua) const;
    KetQuaCapNhatPhuongTien capNhatPhuongTien(
        const std::string& maPhuongTien,
        const ThongTinPhuongTien& thongTin);
    KetQuaXuLyPhuongTien xoaPhuongTien(
        const std::string& maPhuongTien);
    std::vector<ThongTinPhuongTien> layDanhSachPhuongTien() const;
};

#endif
