#ifndef CHUYENXE_H
#define CHUYENXE_H

#include <string>

class IBUUKIENREPOSITORY;

class CHUYENXE {
private:
    std::string ngay_van_chuyen;
    std::string dia_chi_xuat_phat;
    std::string dia_chi_den;
    std::string ma_tai_xe;
    std::string ma_phuong_tien;
    std::string trang_thai;
    IBUUKIENREPOSITORY* ds_buu_kien;

public:
    CHUYENXE(
        const std::string& ngay_van_chuyen = "",
        const std::string& dia_chi_xuat_phat = "",
        const std::string& dia_chi_den = "",
        const std::string& ma_tai_xe = "",
        const std::string& ma_phuong_tien = "",
        const std::string& trang_thai = "",
        IBUUKIENREPOSITORY* ds_buu_kien = nullptr);

    const std::string& GetNgayVanChuyen() const;
    void SetNgayVanChuyen(const std::string& ngayVanChuyenMoi);

    const std::string& GetDiaChiXuatPhat() const;
    void SetDiaChiXuatPhat(const std::string& diaChiXuatPhatMoi);

    const std::string& GetDiaChiDen() const;
    void SetDiaChiDen(const std::string& diaChiDenMoi);

    const std::string& GetMaTaiXe() const;
    void SetMaTaiXe(const std::string& maTaiXeMoi);

    const std::string& GetMaPhuongTien() const;
    void SetMaPhuongTien(const std::string& maPhuongTienMoi);

    const std::string& GetTrangThai() const;
    void SetTrangThai(const std::string& trangThaiMoi);

    IBUUKIENREPOSITORY* GetDsBuuKien() const;
    void SetDsBuuKien(IBUUKIENREPOSITORY& dsBuuKienMoi);
};

#endif
