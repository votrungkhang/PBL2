#ifndef BUUKIENHOATOC_H
#define BUUKIENHOATOC_H

#include<iostream>
#include <string>
#include "BuuKien.h"

using namespace std;

class BuuKienHoaToc : public BuuKien {
private:
    string thoiGianGiaoDuKien;
    // double phuPhiHoaToc = 0;

public:
    BuuKienHoaToc(string,string);
    void Show() override;
    // double tinhPhi() const override;
};


BuuKienHoaToc::BuuKienHoaToc(string maBuuKien,string thoiGianGiaoDuKien)
    :BuuKien(maBuuKien),thoiGianGiaoDuKien(thoiGianGiaoDuKien){
        
    }
void BuuKienHoaToc::Show(){
    cout<<"Day la buu kien hoa toc"<<endl;
}
#endif