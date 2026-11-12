#ifndef KHACHKHANG_H
#define KHACHKHANG_H

#include <string>
using namespace std;

class KHACHHANG {
private:
    string ma_khach_hang;
    string ho_ten;
    string sdt;
    string dia_chi;

public:
    KHACHHANG(
        const string& ma_khach_hang = "",
        const string& ho_ten = "",
        const string& sdt = "",
        const string& dia_chi = "");

    const string& GetMaKhachHang() const;
    void SetMaKhachHang(const string& maKhachHangMoi);

    const string& GetHoTen() const;
    void SetHoTen(const string& hoTenMoi);

    const string& GetSdt() const;
    void SetSdt(const string& sdtMoi);

    const string& GetDiaChi() const;
    void SetDiaChi(const string& diaChiMoi);
};

#endif