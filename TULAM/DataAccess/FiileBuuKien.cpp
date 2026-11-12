#include "FileBuuKien.h"
#include "../Domain/BuuKienBinhThuong.h"
#include "../Domain/BuuKienHoaToc.h"
#include "../Domain/BuuKienNhanh.h"
#include <fstream>
#include <array>
#include <iostream>
#include <stdexcept>
#include <algorithm>

string chuanHoaLoaiBuuKien(const string& loai) {
    string loaiInHoa = loai;
    transform(loaiInHoa.begin(), loaiInHoa.end(), loaiInHoa.begin(),
        [](unsigned char kyTu) {
            return static_cast<char>(toupper(kyTu));
        });

    if (loaiInHoa == "BINH_THUONG"
        || loaiInHoa == "HOA_TOC"
        || loaiInHoa == "NHANH") {
        return loaiInHoa;
    }

    return "";
}

unique_ptr<BUUKIEN> taoBuuKien(string loai) {
    const string loaiInHoa = chuanHoaLoaiBuuKien(loai);
    unique_ptr<BUUKIEN> buuKien;
    if (loaiInHoa == "BINH_THUONG") {
        buuKien = make_unique<BUUKIENBINHTHUONG>();
    } else if (loaiInHoa == "HOA_TOC") {
        buuKien = make_unique<BUUKIENHOATOC>();
    } else if (loaiInHoa == "NHANH") {
        buuKien = make_unique<BUUKIENNHANH>();
    }

    if (buuKien) {
        buuKien->SetLoaiBuuKien(loaiInHoa);
    }
    return buuKien;
}


FILEBUUKIEN::FILEBUUKIEN(const string& nameFile)
    : IFILE(nameFile) {}

namespace {

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

bool FILEBUUKIEN::save(IBUUKIENREPOSITORY& dsbk){
    ofstream file(nameFile);

    if(!file.is_open()){
        return false;
    }

    vector<const BUUKIEN*> danhsachbk=dsbk.getAll();
    
    for(size_t i = 0; i < danhsachbk.size(); ++i){
        file<<danhsachbk[i]->GetMaBuuKien()<<"|";
        file<<danhsachbk[i]->GetLoaiBuuKien()<<"|";
        file<<danhsachbk[i]->GetTrongLuong()<<"|";
        file<<danhsachbk[i]->GetDiaChiGui()<<"|";
        file<<danhsachbk[i]->GetDiaChiNhan()<<"|";
        file<<danhsachbk[i]->GetNgayGui()<<"|";
        file<<danhsachbk[i]->GetTrangThai()<<"|";
        file<<danhsachbk[i]->GetMaNguoiGui()<<"|";
        file<<danhsachbk[i]->GetMaNguoiNhan()<<"|";
        file<<danhsachbk[i]->GetMaNhanVienTiepNhan()<<"|";
        file<<danhsachbk[i]->GetMaChuyen()<<"|";
        file<<danhsachbk[i]->GetPhiDichVu()<<"|";
        file<<danhsachbk[i]->GetThoiGianGiaoDuKien()<<"|";
        file<<danhsachbk[i]->GetTongPhi()<<"\n";
    }
    file.close();
    return !file.fail();
}
bool FILEBUUKIEN::read(IBUUKIENREPOSITORY& dslk){
    ifstream file(nameFile);

    if(!file.is_open()){
        return false;
    }

    string line;
    unique_ptr<BUUKIEN> buuKien;
    try{
        while(getline(file,line)){
            if(line.empty()){
                continue;
            }

            auto f=tachDong(line);
            unique_ptr<BUUKIEN> buuKien = taoBuuKien(f[1]);

            buuKien->SetMaBuuKien(f[0]);
            buuKien->SetLoaiBuuKien(f[1]);
            buuKien->SetTrongLuong(stod(f[2]));
            buuKien->SetDiaChiGui(f[3]);
            buuKien->SetDiaChiNhan(f[4]);
            buuKien->SetNgayGui(f[5]);

            buuKien->SetTrangThai(f[6]);
            buuKien->SetMaNguoiGui(f[7]);
            buuKien->SetMaNguoiNhan(f[8]);
            buuKien->SetMaNhanVienTiepNhan(f[9]);
            buuKien->SetMaChuyen(f[10]);
            buuKien->SetPhiDichVu(stod(f[11]));
            buuKien->SetThoiGianGiaoDuKien(f[12]);
            buuKien->SetTongPhi(stod(f[13]));

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