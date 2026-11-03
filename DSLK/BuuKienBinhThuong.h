#ifndef BUUKIENBINHTHUONG_H
#define BUUKIENBINHTHUONG_H

#include<iostream>
#include <string>
#include "BuuKien.h"

using namespace std;

class BuuKienBinhThuong : public BuuKien {
private:
    string thoiGianGiaoDuKien;
    // double phuPhiDichVu = 0;

public:
    BuuKienBinhThuong(string,string);
    void Show() override;
    // double tinhPhi() const override;
};

BuuKienBinhThuong::BuuKienBinhThuong(string maBuuKien,string thoiGianGiaoDuKien)
    :BuuKien(maBuuKien),thoiGianGiaoDuKien(thoiGianGiaoDuKien){

    }
void BuuKienBinhThuong::Show(){
    cout<<"Day la buu kien binh thuong"<<endl;
}
#endif