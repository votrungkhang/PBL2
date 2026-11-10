#include "ConsoleUI.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

namespace {
string tenLoaiBuuKien(LoaiBuuKien loai) {
    switch (loai) {
    case LoaiBuuKien::BINH_THUONG:
        return "BINH_THUONG";
    case LoaiBuuKien::HOA_TOC:
        return "HOA_TOC";
    case LoaiBuuKien::NHANH:
        return "NHANH";
    default:
        return "CHUA_XAC_DINH";
    }
}

template <typename Number>
bool nhapSo(const string& loiNhac, Number& giaTri) {
    string dong;
    cout << loiNhac;
    if (!getline(cin, dong)) {
        return false;
    }

    istringstream input(dong);
    if (!(input >> giaTri)) {
        cout << "Gia tri khong hop le, vui long nhap lai.\n";
        return false;
    }
    input >> ws;
    if (!input.eof()) {
        cout << "Gia tri khong hop le, vui long nhap lai.\n";
        return false;
    }
    return true;
}

bool nhapSoThuc(const string& loiNhac, double& giaTri) {
    return nhapSo(loiNhac, giaTri);
}
}

ConsoleUI::ConsoleUI(BuuKienService& service)
    : service(service) {}

int ConsoleUI::run() {
    int luaChon = -1;
    while (luaChon != 0) {
        string dongLuaChon;
        cout << "\n=== QUAN LY BUU KIEN ===\n"
                  << "1. Them buu kien\n"
                  << "2. Hien thi danh sach\n"
                  << "0. Thoat\n"
                  << "Lua chon: ";

        if (!getline(cin, dongLuaChon)) {
            return 0;
        }
        istringstream inputLuaChon(dongLuaChon);
        if (!(inputLuaChon >> luaChon)) {
            cout << "Lua chon khong hop le.\n";
            continue;
        }
        inputLuaChon >> ws;
        if (!inputLuaChon.eof()) {
            cout << "Lua chon khong hop le.\n";
            continue;
        }

        switch (luaChon) {
        case 1:
            themBuuKien();
            break;
        case 2:
            hienThiDanhSach();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
    return 0;
}

void ConsoleUI::themBuuKien() {
    ThongTinBuuKien thongTin;

    cout << "Nhap ma buu kien: ";
    if (!getline(cin, thongTin.maBuuKien)) {
        return;
    }

    int loaiBuuKien;
    if (!nhapSo("Loai (1: Binh thuong, 2: Hoa toc, 3: Nhanh): ",
                loaiBuuKien)
        || loaiBuuKien < 1 || loaiBuuKien > 3) {
        cout << "Loai buu kien khong hop le.\n";
        return;
    }

    switch (loaiBuuKien) {
    case 1:
        thongTin.loaiBuuKien = LoaiBuuKien::BINH_THUONG;
        break;
    case 2:
        thongTin.loaiBuuKien = LoaiBuuKien::HOA_TOC;
        break;
    case 3:
        thongTin.loaiBuuKien = LoaiBuuKien::NHANH;
        break;
    }

    if (!nhapSoThuc("Nhap trong luong: ", thongTin.trongLuong)) return;

    cout << "Nhap dia chi gui: ";
    if (!getline(cin, thongTin.diaChiGui)) return;
    cout << "Nhap dia chi nhan: ";
    if (!getline(cin, thongTin.diaChiNhan)) return;
    cout << "Nhap ngay gui: ";
    if (!getline(cin, thongTin.ngayGui)) return;
    cout << "Nhap trang thai: ";
    if (!getline(cin, thongTin.trangThai)) return;
    cout << "Nhap ma nguoi gui: ";
    if (!getline(cin, thongTin.maNguoiGui)) return;
    cout << "Nhap ma nguoi nhan: ";
    if (!getline(cin, thongTin.maNguoiNhan)) return;
    cout << "Nhap ma nhan vien tiep nhan: ";
    if (!getline(cin, thongTin.maNhanVienTiepNhan)) return;
    cout << "Nhap ma chuyen: ";
    if (!getline(cin, thongTin.maChuyen)) return;
    if (!nhapSoThuc("Nhap phi dich vu: ", thongTin.phiDichVu)) return;
    cout << "Nhap thoi gian giao du kien: ";
    if (!getline(cin, thongTin.thoiGianGiaoDuKien)) return;
    if (!nhapSoThuc("Nhap tong phi: ", thongTin.tongPhi)) return;

    switch (service.themBuuKien(thongTin)) {
    case KetQuaThemBuuKien::THANH_CONG:
        cout << "Them buu kien thanh cong.\n";
        break;
    case KetQuaThemBuuKien::MA_TRONG:
        cout << "Ma buu kien khong duoc de trong.\n";
        break;
    case KetQuaThemBuuKien::MA_DA_TON_TAI:
        cout << "Ma buu kien da ton tai.\n";
        break;
    case KetQuaThemBuuKien::LOAI_KHONG_HOP_LE:
        cout << "Loai buu kien khong hop le.\n";
        break;
    case KetQuaThemBuuKien::LOI_LUU_TRU:
        cout << "Khong the luu buu kien.\n";
        break;
    }
}

void ConsoleUI::hienThiDanhSach() const {
    const vector<ThongTinBuuKien> danhSach =
        service.layDanhSachBuuKien();
    if (danhSach.empty()) {
        cout << "Danh sach buu kien dang trong.\n";
        return;
    }

    const string duongKe(76, '=');
    const string phanCach(76, '-');

    cout << '\n' << duongKe << '\n'
         << "                 DANH SACH BUU KIEN (" << danhSach.size()
         << " buu kien)\n"
         << duongKe << '\n';

    for (size_t i = 0; i < danhSach.size(); ++i) {
        const ThongTinBuuKien& buuKien = danhSach[i];

        cout << "BUU KIEN " << i + 1 << '\n'
             << phanCach << '\n'
             << left << setw(26) << "Loai"
             << ": " << tenLoaiBuuKien(buuKien.loaiBuuKien) << '\n'
             << left << setw(26) << "Ma buu kien"
             << ": " << buuKien.maBuuKien << '\n'
             << left << setw(26) << "Trong luong"
             << ": " << buuKien.trongLuong << '\n'
             << left << setw(26) << "Dia chi gui"
             << ": " << buuKien.diaChiGui << '\n'
             << left << setw(26) << "Dia chi nhan"
             << ": " << buuKien.diaChiNhan << '\n'
             << left << setw(26) << "Ngay gui"
             << ": " << buuKien.ngayGui << '\n'
             << left << setw(26) << "Trang thai"
             << ": " << buuKien.trangThai << '\n'
             << left << setw(26) << "Ma nguoi gui"
             << ": " << buuKien.maNguoiGui << '\n'
             << left << setw(26) << "Ma nguoi nhan"
             << ": " << buuKien.maNguoiNhan << '\n'
             << left << setw(26) << "Ma nhan vien tiep nhan"
             << ": " << buuKien.maNhanVienTiepNhan << '\n'
             << left << setw(26) << "Ma chuyen"
             << ": " << buuKien.maChuyen << '\n'
             << left << setw(26) << "Phi dich vu"
             << ": " << buuKien.phiDichVu << '\n'
             << left << setw(26) << "Thoi gian giao du kien"
             << ": " << buuKien.thoiGianGiaoDuKien << '\n'
             << left << setw(26) << "Tong phi"
             << ": " << buuKien.tongPhi << '\n'
             << duongKe << '\n';
    }
}
