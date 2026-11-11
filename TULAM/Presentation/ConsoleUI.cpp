#include "ConsoleUI.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

namespace {
void hienThiThongTinBuuKien(
    const ThongTinBuuKien& buuKien,
    const string& tieuDe) {
    const string duongKe(76, '=');
    const string phanCach(76, '-');

    cout << '\n' << duongKe << '\n'
         << tieuDe << '\n'
         << phanCach << '\n'
         << left << setw(26) << "Loai"
         << ": " << buuKien.loaiBuuKien << '\n'
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

template <typename Number>
bool nhapSo(const string& loiNhac, Number& giaTri);
bool nhapSoThuc(const string& loiNhac, double& giaTri);

bool nhapThongTinBuuKien(ThongTinBuuKien& thongTin) {
    cout << "Nhap loai buu kien (BINH_THUONG, HOA_TOC, NHANH): ";
    if (!getline(cin, thongTin.loaiBuuKien)) return false;

    if (!nhapSoThuc("Nhap trong luong: ", thongTin.trongLuong)) return false;

    cout << "Nhap dia chi gui: ";
    if (!getline(cin, thongTin.diaChiGui)) return false;
    cout << "Nhap dia chi nhan: ";
    if (!getline(cin, thongTin.diaChiNhan)) return false;
    cout << "Nhap ngay gui: ";
    if (!getline(cin, thongTin.ngayGui)) return false;
    cout << "Nhap trang thai: ";
    if (!getline(cin, thongTin.trangThai)) return false;
    cout << "Nhap ma nguoi gui: ";
    if (!getline(cin, thongTin.maNguoiGui)) return false;
    cout << "Nhap ma nguoi nhan: ";
    if (!getline(cin, thongTin.maNguoiNhan)) return false;
    cout << "Nhap ma nhan vien tiep nhan: ";
    if (!getline(cin, thongTin.maNhanVienTiepNhan)) return false;
    cout << "Nhap ma chuyen: ";
    if (!getline(cin, thongTin.maChuyen)) return false;
    if (!nhapSoThuc("Nhap phi dich vu: ", thongTin.phiDichVu)) return false;
    cout << "Nhap thoi gian giao du kien: ";
    if (!getline(cin, thongTin.thoiGianGiaoDuKien)) return false;
    if (!nhapSoThuc("Nhap tong phi: ", thongTin.tongPhi)) return false;
    return true;
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
                  << "3. Tim buu kien theo ma\n"
                  << "4. Cap nhat buu kien\n"
                  << "5. Huy buu kien (giu lich su)\n"
                  << "6. Xoa vinh vien buu kien\n"
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
        case 3:
            timKiemBuuKien();
            break;
        case 4:
            capNhatBuuKien();
            break;
        case 5:
            huyBuuKien();
            break;
        case 6:
            xoaBuuKien();
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

    if (!nhapThongTinBuuKien(thongTin)) return;

    switch (service.themBuuKien(thongTin)) {
    case KetQuaThemBuuKien::THANH_CONG:
        cout << "Them buu kien thanh cong. Ma buu kien: "
             << thongTin.maBuuKien << '\n';
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

void ConsoleUI::timKiemBuuKien() const {
    string maBuuKien;
    cout << "Nhap ma buu kien can tim: ";
    if (!getline(cin, maBuuKien)) {
        return;
    }
    if (maBuuKien.empty()) {
        cout << "Ma buu kien khong duoc de trong.\n";
        return;
    }

    ThongTinBuuKien ketQua;
    if (!service.timBuuKienTheoMa(maBuuKien, ketQua)) {
        cout << "Khong tim thay buu kien co ma " << maBuuKien << ".\n";
        return;
    }

    hienThiThongTinBuuKien(ketQua, "KET QUA TIM KIEM");
}

void ConsoleUI::capNhatBuuKien() {
    string maBuuKien;
    cout << "Nhap ma buu kien can cap nhat: ";
    if (!getline(cin, maBuuKien)) {
        return;
    }
    if (maBuuKien.empty()) {
        cout << "Ma buu kien khong duoc de trong.\n";
        return;
    }

    ThongTinBuuKien thongTin;
    if (!service.timBuuKienTheoMa(maBuuKien, thongTin)) {
        cout << "Khong tim thay buu kien co ma " << maBuuKien << ".\n";
        return;
    }

    hienThiThongTinBuuKien(thongTin, "THONG TIN HIEN TAI");
    cout << "Nhap thong tin moi (ma buu kien se duoc giu nguyen):\n";
    if (!nhapThongTinBuuKien(thongTin)) {
        return;
    }

    switch (service.capNhatBuuKien(maBuuKien, thongTin)) {
    case KetQuaCapNhatBuuKien::THANH_CONG:
        cout << "Cap nhat buu kien thanh cong.\n";
        break;
    case KetQuaCapNhatBuuKien::KHONG_TIM_THAY:
        cout << "Khong tim thay buu kien de cap nhat.\n";
        break;
    case KetQuaCapNhatBuuKien::LOAI_KHONG_HOP_LE:
        cout << "Loai buu kien khong hop le.\n";
        break;
    case KetQuaCapNhatBuuKien::LOI_LUU_TRU:
        cout << "Khong the cap nhat buu kien.\n";
        break;
    }
}

void ConsoleUI::huyBuuKien() {
    string maBuuKien;
    cout << "Nhap ma buu kien can huy: ";
    if (!getline(cin, maBuuKien)) {
        return;
    }
    if (maBuuKien.empty()) {
        cout << "Ma buu kien khong duoc de trong.\n";
        return;
    }

    switch (service.huyBuuKien(maBuuKien)) {
    case KetQuaXuLyBuuKien::THANH_CONG:
        cout << "Da huy buu kien; thong tin va lich su duoc giu lai.\n";
        break;
    case KetQuaXuLyBuuKien::KHONG_TIM_THAY:
        cout << "Khong tim thay buu kien co ma " << maBuuKien << ".\n";
        break;
    case KetQuaXuLyBuuKien::DA_HUY:
        cout << "Buu kien nay da duoc huy truoc do.\n";
        break;
    case KetQuaXuLyBuuKien::LOI_LUU_TRU:
        cout << "Khong the cap nhat trang thai buu kien.\n";
        break;
    }
}

void ConsoleUI::xoaBuuKien() {
    string maBuuKien;
    cout << "Nhap ma buu kien can xoa vinh vien: ";
    if (!getline(cin, maBuuKien)) {
        return;
    }
    if (maBuuKien.empty()) {
        cout << "Ma buu kien khong duoc de trong.\n";
        return;
    }

    ThongTinBuuKien thongTin;
    if (!service.timBuuKienTheoMa(maBuuKien, thongTin)) {
        cout << "Khong tim thay buu kien co ma " << maBuuKien << ".\n";
        return;
    }
    hienThiThongTinBuuKien(thongTin, "BUU KIEN SE BI XOA VINH VIEN");

    string xacNhan;
    cout << "Nhap XOA de xac nhan xoa vinh vien: ";
    if (!getline(cin, xacNhan) || xacNhan != "XOA") {
        cout << "Da huy thao tac xoa.\n";
        return;
    }

    switch (service.xoaBuuKien(maBuuKien)) {
    case KetQuaXuLyBuuKien::THANH_CONG:
        cout << "Da xoa vinh vien buu kien.\n";
        break;
    case KetQuaXuLyBuuKien::KHONG_TIM_THAY:
        cout << "Khong tim thay buu kien co ma " << maBuuKien << ".\n";
        break;
    case KetQuaXuLyBuuKien::DA_HUY:
        break;
    case KetQuaXuLyBuuKien::LOI_LUU_TRU:
        cout << "Khong the xoa buu kien.\n";
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

    cout << "\nDANH SACH BUU KIEN (" << danhSach.size()
         << " buu kien)\n";

    for (size_t i = 0; i < danhSach.size(); ++i) {
        hienThiThongTinBuuKien(
            danhSach[i], "BUU KIEN " + to_string(i + 1));
    }
}
