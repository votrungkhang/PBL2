#ifndef QUANLY_H
#define QUANLY_H
#include"dslk.h"
#include"BuuKienBinhThuong.h"
#include"BuuKienHoaToc.h"
#include"BuuKienNhanh.h"
class QuanLy
{
private:
    LinkedList& CTDL;
public:
    QuanLy(LinkedList&);
    void themBuuKien();
    void Show();
    // ~QuanLy();
};

QuanLy::QuanLy(LinkedList& ctdl):CTDL(ctdl)
{
}

void QuanLy::themBuuKien(){
    string maBuuKien;
    int loai;
    cout<<"Nhap ma Buu Kien";
    cin>>maBuuKien;
    cout<<"Nhap loai Buu Kien";
    cin>>loai;
    BuuKien *temp;
    if(loai==1){
        temp =new BuuKienBinhThuong(maBuuKien,"04/11/2026");
    }
    if(loai==2){
        temp =new BuuKienHoaToc(maBuuKien,"04/11/2026");
    }
    if(loai==3){
        temp =new BuuKienNhanh(maBuuKien,"04/11/2026");
    }
    this->CTDL.pushBack(temp);
    cout<<"Them thanh cong"<<endl;
}

void QuanLy::Show(){
    this->CTDL.display();
}
// QuanLy::~QuanLy()
// {
// }
#endif