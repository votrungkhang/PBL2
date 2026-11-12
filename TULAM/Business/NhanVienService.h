#ifndef NHANVIENSERVICE_H
#define NHANVIENSERVICE_H

#include <cstddef>
#include <string>
#include <vector>

class INHANVIENREPOSITORY;

struct ThongTinNhanVien {
    std::string maNhanVien;
    std::string hoTen;
    std::string chucVu;
    std::string sdt;
};

enum class KetQuaThemNhanVien {
    THANH_CONG,
    MA_TRONG,
    LOI_LUU_TRU
};

enum class KetQuaCapNhatNhanVien {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOI_LUU_TRU
};

enum class KetQuaXuLyNhanVien {
    THANH_CONG,
    KHONG_TIM_THAY,
    LOI_LUU_TRU
};

class NHANVIENSERVICE {
private:
    INHANVIENREPOSITORY& repository;
    std::size_t soThuTuNhanVienDaTao;

public:
    explicit NHANVIENSERVICE(INHANVIENREPOSITORY& repository);

    KetQuaThemNhanVien themNhanVien(ThongTinNhanVien& thongTin);
    bool timNhanVienTheoMa(
        const std::string& maNhanVien,
        ThongTinNhanVien& ketQua) const;
    KetQuaCapNhatNhanVien capNhatNhanVien(
        const std::string& maNhanVien,
        const ThongTinNhanVien& thongTin);
    KetQuaXuLyNhanVien xoaNhanVien(const std::string& maNhanVien);
    std::vector<ThongTinNhanVien> layDanhSachNhanVien() const;
};

#endif
