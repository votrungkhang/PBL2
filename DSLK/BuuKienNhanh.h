#ifndef BUUKIENNHANH_H
#define BUUKIENNHANH_H

#include<iostream>
#include <string>
#include "BuuKien.h"

using namespace std;

class BuuKienNhanh : public BuuKien {
private:
    string thoiGianGiaoDuKien;
    // double phuPhiNhanh = 0;

public:
    BuuKienNhanh(string,string);
    void Show() override;
    // double tinhPhi() const override;
};
BuuKienNhanh::BuuKienNhanh(string maBuuKien,string thoiGianGiaoDuKien)
    :BuuKien(maBuuKien),thoiGianGiaoDuKien(thoiGianGiaoDuKien){
        
    }

void BuuKienNhanh::Show(){
    cout<<"Day la buu kien Nhanh"<<endl;
}
#endif