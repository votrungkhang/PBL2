#include "FileBuuKien.h"
#include "../Domain/BuuKienBinhThuong.h"
#include "../Domain/BuuKienHoaToc.h"
#include "../Domain/BuuKienNhanh.h"
#include <fstream>
#include <array>
#include <iostream>
#include <stdexcept>

FileBuuKien::FileBuuKien(const string& nameFile)
    : IFileBuuKien(nameFile) {}

namespace {
string chuyenLoaiSangString(const LoaiBuuKien & loaibuukien){
    if(loaibuukien==LoaiBuuKien::BINH_THUONG){
        return "BINH_THUONG";
    }
    else if(loaibuukien==LoaiBuuKien::HOA_TOC){
        return "HOA_TOC";
    }
    else if(loaibuukien==LoaiBuuKien::NHANH){
        return "NHANH";
    }
    else{
        return "CHUA_XAC_DINH";
    }
}


LoaiBuuKien chuyenStringSangLoai(const string & loaibuukien){
    if(loaibuukien=="BINH_THUONG" || loaibuukien=="BINHTHUONG"){
        return LoaiBuuKien::BINH_THUONG;
    }
    else if(loaibuukien=="HOA_TOC" || loaibuukien=="HOATOC"){
        return  LoaiBuuKien::HOA_TOC;
    }
    else if(loaibuukien=="NHANH"){
        return  LoaiBuuKien::NHANH;
    }
    else{
        return LoaiBuuKien::CHUA_XAC_DINH;
    }
}



array<string, 14> tachDong(const string& line) {
    array<string, 14> fields;

    size_t start = 0;

    for (int i = 0; i < 13; i++) {
        size_t pos = line.find('|', start);

        if (pos == string::npos) {
            throw runtime_error("Thieu truong du lieu");
        }

        fields[i] = line.substr(start, pos - start);

        start = pos + 1;
    }

    fields[13] = line.substr(start);

    if (fields[13].find('|') != string::npos) {
        throw runtime_error("Thua truong du lieu");
    }

    return fields;
}
}

bool FileBuuKien::save(IBuuKienRepository& dsbk){
    ofstream file(nameFile);

    if(!file.is_open()){
        return false;
    }

    vector<const BuuKien*> danhsachbk=dsbk.getAll();
    
    for(size_t i = 0; i < danhsachbk.size(); ++i){
        file<<chuyenLoaiSangString(danhsachbk[i]->getLoaiBuuKien())<<"|";
        file<<danhsachbk[i]->getMaBuuKien()<<"|";
        file<<danhsachbk[i]->getTrongLuong()<<"|";
        file<<danhsachbk[i]->getDiaChiGui()<<"|";
        file<<danhsachbk[i]->getDiaChiNhan()<<"|";
        file<<danhsachbk[i]->getNgayGui()<<"|";
        file<<danhsachbk[i]->getTrangThai()<<"|";
        file<<danhsachbk[i]->getMaNguoiGui()<<"|";
        file<<danhsachbk[i]->getMaNguoiNhan()<<"|";
        file<<danhsachbk[i]->getMaNhanVienTiepNhan()<<"|";
        file<<danhsachbk[i]->getMaChuyen()<<"|";
        file<<danhsachbk[i]->getPhiDichVu()<<"|";
        file<<danhsachbk[i]->getThoiGianGiaoDuKien()<<"|";
        file<<danhsachbk[i]->getTongPhi()<<"\n";
    }
    file.close();
    return !file.fail();
}
bool FileBuuKien::read(IBuuKienRepository& dslk){
    ifstream file(nameFile);

    if(!file.is_open()){
        return false;
    }

    string line;
    unique_ptr<BuuKien> buuKien;
    try{
        while(getline(file,line)){
            if(line.empty()){
                continue;
            }

            auto f=tachDong(line);
            LoaiBuuKien loai=chuyenStringSangLoai(f[0]);
            switch (loai) {
                case LoaiBuuKien::BINH_THUONG :
                    buuKien.reset(new BuuKienBinhThuong);
                    break;
                case LoaiBuuKien::HOA_TOC:
                    buuKien.reset(new BuuKienHoaToc);
                    break;
                case LoaiBuuKien::NHANH:
                    buuKien.reset(new BuuKienNhanh) ;
                    break;
                default:
                    throw runtime_error("Buu kien chua phan loai");
            }

            buuKien->setMaBuuKien(f[1]);
            buuKien->setTrongLuong(stod(f[2]));
            buuKien->setDiaChiGui(f[3]);
            buuKien->setDiaChiNhan(f[4]);
            buuKien->setNgayGui(f[5]);

            buuKien->setTrangThai(f[6]);
            buuKien->setMaNguoiGui(f[7]);
            buuKien->setMaNguoiNhan(f[8]);
            buuKien->setMaNhanVienTiepNhan(f[9]);
            buuKien->setMaChuyen(f[10]);
            buuKien->setPhiDichVu(stod(f[11]));
            buuKien->setThoiGianGiaoDuKien(f[12]);
            buuKien->setTongPhi(stod(f[13]));

            if (!dslk.add(move(buuKien))) {
                return false;
            }
        }
        if(file.bad()){
            return false;
        }
        return true;
    }
    catch (const exception& e) {
        cerr << "Loi doc file: "
             << e.what() << endl;
        return false;
    }
}