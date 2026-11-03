#ifndef BUUKIEN_H
#define BUUKIEN_H

#include <string>
#include "Enums.h"

using namespace std;

class BuuKien {
protected:
    string maBuuKien;
    // double trongLuong = 0;

    // string diaChiGui;
    // string diaChiNhan;
    // string ngayGui;

    // TrangThaiBuuKien trangThai =
    //     TrangThaiBuuKien::CHO_XU_LY;

    // string maNguoiGui;
    // string maNguoiNhan;
    // string maNhanVienTiepNhan;
    // string maChuyen;

    // double phiDichVu = 0;

public:
    BuuKien(string );
    virtual void Show()=0;
    string getMaBuuKien();
    void setMaBuuKien(const string&);
    // virtual ~BuuKien() = default;

    // // Tinh phi theo tung loai buu kien
    // virtual double tinhPhi() const = 0;
};


BuuKien::BuuKien(string maBuuKien ):maBuuKien(maBuuKien){}
string BuuKien::getMaBuuKien(){
    return this->maBuuKien;
}
void BuuKien::setMaBuuKien(const string& maMoi){
    this->maBuuKien=maMoi;
}
#endif