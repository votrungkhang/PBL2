#ifndef PHUONGTIEN_H
#define PHUONGTIEN_H

#include <string>

class PHUONGTIEN {
private:
    std::string ma_phuong_tien;
    std::string bien_so;
    std::string loai_xe;
    double tai_trong_toi_da;
    std::string trang_thai;

public:
    PHUONGTIEN(
        const std::string& ma_phuong_tien = "",
        const std::string& bien_so = "",
        const std::string& loai_xe = "",
        double tai_trong_toi_da = 0.0,
        const std::string& trang_thai = "");

    const std::string& GetMaPhuongTien() const;
    void SetMaPhuongTien(const std::string& maPhuongTienMoi);

    const std::string& GetBienSo() const;
    void SetBienSo(const std::string& bienSoMoi);

    const std::string& GetLoaiXe() const;
    void SetLoaiXe(const std::string& loaiXeMoi);

    double GetTaiTrongToiDa() const;
    void SetTaiTrongToiDa(double taiTrongToiDaMoi);

    const std::string& GetTrangThai() const;
    void SetTrangThai(const std::string& trangThaiMoi);
};

#endif
