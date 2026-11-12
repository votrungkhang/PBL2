#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

class NHANVIEN {
private:
    string ma_nhan_vien;
    string ho_ten;
    string chuc_vu;
    string sdt;

public:
    NHANVIEN(
        const string& ma_nhan_vien = "",
        const string& ho_ten = "",
        const string& chuc_vu = "",
        const string& sdt = "");

    const string& GetMaNhanVien() const;
    void SetMaNhanVien(const string& maNhanVienMoi);

    const string& GetHoTen() const;
    void SetHoTen(const string& hoTenMoi);

    const string& GetChucVu() const;
    void SetChucVu(const string& chucVuMoi);

    const string& GetSdt() const;
    void SetSdt(const string& sdtMoi);
};

#endif
