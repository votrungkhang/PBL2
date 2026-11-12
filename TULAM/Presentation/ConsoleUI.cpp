#include "ConsoleUI.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
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
         << left << setw(26) << "Ma buu kien"
         << ": " << buuKien.maBuuKien << '\n'
         << left << setw(26) << "Loai"
         << ": " << buuKien.loaiBuuKien << '\n'
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

void hienThiThongTinKhachHang(
    const ThongTinKhachHang& khachHang,
    const string& tieuDe) {
    const string duongKe(60, '=');
    cout << '\n' << duongKe << '\n'
         << tieuDe << '\n'
         << left << setw(24) << "Ma khach hang"
         << ": " << khachHang.maKhachHang << '\n'
         << left << setw(24) << "Ho ten"
         << ": " << khachHang.hoTen << '\n'
         << left << setw(24) << "So dien thoai"
         << ": " << khachHang.sdt << '\n'
         << left << setw(24) << "Dia chi"
         << ": " << khachHang.diaChi << '\n'
         << duongKe << '\n';
}

void hienThiThongTinNhanVien(
    const ThongTinNhanVien& nhanVien,
    const string& tieuDe) {
    const string duongKe(60, '=');
    cout << '\n' << duongKe << '\n'
         << tieuDe << '\n'
         << left << setw(24) << "Ma nhan vien"
         << ": " << nhanVien.maNhanVien << '\n'
         << left << setw(24) << "Ho ten"
         << ": " << nhanVien.hoTen << '\n'
         << left << setw(24) << "Chuc vu"
         << ": " << nhanVien.chucVu << '\n'
         << left << setw(24) << "So dien thoai"
         << ": " << nhanVien.sdt << '\n'
         << duongKe << '\n';
}

void hienThiThongTinTaiXe(
    const ThongTinTaiXe& taiXe,
    const string& tieuDe) {
    const string duongKe(60, '=');
    cout << '\n' << duongKe << '\n'
         << tieuDe << '\n'
         << left << setw(24) << "Ma tai xe"
         << ": " << taiXe.maTaiXe << '\n'
         << left << setw(24) << "Ho ten"
         << ": " << taiXe.hoTen << '\n'
         << left << setw(24) << "So dien thoai"
         << ": " << taiXe.sdt << '\n'
         << left << setw(24) << "Hang bang lai"
         << ": " << taiXe.bangLai << '\n'
         << duongKe << '\n';
}

void hienThiThongTinPhuongTien(
    const ThongTinPhuongTien& phuongTien,
    const string& tieuDe) {
    const string duongKe(60, '=');
    cout << '\n' << duongKe << '\n'
         << tieuDe << '\n'
         << left << setw(24) << "Ma phuong tien"
         << ": " << phuongTien.maPhuongTien << '\n'
         << left << setw(24) << "Bien so"
         << ": " << phuongTien.bienSo << '\n'
         << left << setw(24) << "Loai xe"
         << ": " << phuongTien.loaiXe << '\n'
         << left << setw(24) << "Tai trong toi da"
         << ": " << phuongTien.taiTrongToiDa << '\n'
         << left << setw(24) << "Trang thai"
         << ": " << phuongTien.trangThai << '\n'
         << duongKe << '\n';
}

string chuanHoaTieuChi(string giaTri) {
    const size_t viTriDau = giaTri.find_first_not_of(" \t\r\n");
    if (viTriDau == string::npos) {
        return "";
    }

    const size_t viTriCuoi = giaTri.find_last_not_of(" \t\r\n");
    giaTri = giaTri.substr(viTriDau, viTriCuoi - viTriDau + 1);
    transform(giaTri.begin(), giaTri.end(), giaTri.begin(),
        [](unsigned char kyTu) {
            return static_cast<char>(toupper(kyTu));
        });
    return giaTri;
}

void hienThiDanhSachBuuKien(
    const vector<ThongTinBuuKien>& danhSach,
    const string& tieuDe) {
    if (danhSach.empty()) {
        cout << tieuDe << ": khong co buu kien phu hop.\n";
        return;
    }

    cout << '\n' << tieuDe << " (" << danhSach.size()
         << " buu kien)\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        hienThiThongTinBuuKien(
            danhSach[i], "BUU KIEN " + to_string(i + 1));
    }
}

void inDanhSachKhachHang(
    const vector<ThongTinKhachHang>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach khach hang dang trong.\n";
        return;
    }

    cout << "\nDANH SACH KHACH HANG (" << danhSach.size()
         << " khach hang)\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        hienThiThongTinKhachHang(
            danhSach[i], "KHACH HANG " + to_string(i + 1));
    }
}

void inDanhSachNhanVien(
    const vector<ThongTinNhanVien>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach nhan vien dang trong.\n";
        return;
    }

    cout << "\nDANH SACH NHAN VIEN (" << danhSach.size()
         << " nhan vien)\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        hienThiThongTinNhanVien(
            danhSach[i], "NHAN VIEN " + to_string(i + 1));
    }
}

void inDanhSachTaiXe(const vector<ThongTinTaiXe>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach tai xe dang trong.\n";
        return;
    }

    cout << "\nDANH SACH TAI XE (" << danhSach.size()
         << " tai xe)\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        hienThiThongTinTaiXe(
            danhSach[i], "TAI XE " + to_string(i + 1));
    }
}

void inDanhSachPhuongTien(
    const vector<ThongTinPhuongTien>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach phuong tien dang trong.\n";
        return;
    }

    cout << "\nDANH SACH PHUONG TIEN (" << danhSach.size()
         << " phuong tien)\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        hienThiThongTinPhuongTien(
            danhSach[i], "PHUONG TIEN " + to_string(i + 1));
    }
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
    cout << "Nhap trang thai (CHO_XU_LY, DA_TIEP_NHAN, "
            "DANG_VAN_CHUYEN, DA_GIAO, GIAO_THAT_BAI, DA_HUY): ";
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

bool nhapThongTinKhachHang(ThongTinKhachHang& thongTin) {
    cout << "Nhap ho ten: ";
    if (!getline(cin, thongTin.hoTen)) return false;
    cout << "Nhap so dien thoai: ";
    if (!getline(cin, thongTin.sdt)) return false;
    cout << "Nhap dia chi: ";
    if (!getline(cin, thongTin.diaChi)) return false;
    return true;
}

bool nhapThongTinNhanVien(ThongTinNhanVien& thongTin) {
    cout << "Nhap ho ten: ";
    if (!getline(cin, thongTin.hoTen)) return false;
    cout << "Nhap chuc vu (Nhan vien/Quan ly): ";
    if (!getline(cin, thongTin.chucVu)) return false;
    cout << "Nhap so dien thoai: ";
    if (!getline(cin, thongTin.sdt)) return false;
    return true;
}

bool nhapThongTinTaiXe(ThongTinTaiXe& thongTin) {
    cout << "Nhap ho ten: ";
    if (!getline(cin, thongTin.hoTen)) return false;
    cout << "Nhap so dien thoai: ";
    if (!getline(cin, thongTin.sdt)) return false;
    cout << "Nhap hang bang lai: ";
    if (!getline(cin, thongTin.bangLai)) return false;
    return true;
}

bool nhapThongTinPhuongTien(ThongTinPhuongTien& thongTin) {
    cout << "Nhap bien so xe: ";
    if (!getline(cin, thongTin.bienSo)) return false;
    cout << "Nhap loai phuong tien: ";
    if (!getline(cin, thongTin.loaiXe)) return false;
    if (!nhapSoThuc(
            "Nhap tai trong toi da: ", thongTin.taiTrongToiDa)) {
        return false;
    }
    cout << "Nhap trang thai (SAN_SANG/BAO_TRI): ";
    if (!getline(cin, thongTin.trangThai)) return false;
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

CONSOLEUI::CONSOLEUI(
    BUUKIENSERVICE& buuKienService,
    KHACHHANGSERVICE& khachHangService,
    NHANVIENSERVICE& nhanVienService,
    TAIXESERVICE& taiXeService,
    PHUONGTIENSERVICE& phuongTienService)
    : buuKienService(buuKienService),
      khachHangService(khachHangService),
      nhanVienService(nhanVienService),
      taiXeService(taiXeService),
      phuongTienService(phuongTienService) {}

int CONSOLEUI::run() {
    int luaChon = -1;
    while (true) {
        string dongLuaChon;
        cout << "\n=== HE THONG QUAN LY ===\n"
                  << "1. Quan ly buu kien\n"
                  << "2. Quan ly khach hang\n"
                  << "3. Quan ly nhan vien\n"
                  << "4. Quan ly tai xe\n"
                  << "5. Quan ly phuong tien\n"
                  << "0. Thoat\n"
                  << "Buu kien, khach hang, nhan vien, tai xe va phuong tien: "
                     "tu dong doc khi khoi dong, luu khi thoat.\n"
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
            menuQuanLyBuuKien();
            break;
        case 2:
            menuQuanLyKhachHang();
            break;
        case 3:
            menuQuanLyNhanVien();
            break;
        case 4:
            menuQuanLyTaiXe();
            break;
        case 5:
            menuQuanLyPhuongTien();
            break;
        case 0:
            return 0;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void CONSOLEUI::menuQuanLyBuuKien() {
    int luaChon = -1;
    while (true) {
        string dongLuaChon;
        cout << "\n=== QUAN LY BUU KIEN ===\n"
             << "1. Them buu kien\n"
             << "2. Cap nhat thong tin\n"
             << "3. Huy buu kien (giu lich su)\n"
             << "4. Xoa vinh vien\n"
             << "5. Tim kiem va thong ke\n"
             << "0. Quay lai\n"
             << "Lua chon: ";

        if (!getline(cin, dongLuaChon)) {
            return;
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
            capNhatBuuKien();
            break;
        case 3:
            huyBuuKien();
            break;
        case 4:
            xoaBuuKien();
            break;
        case 5:
            menuTimKiemVaThongKe();
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void CONSOLEUI::menuQuanLyKhachHang() {
    int luaChon = -1;
    while (true) {
        string dongLuaChon;
        cout << "\n=== QUAN LY KHACH HANG ===\n"
             << "1. Them khach hang\n"
             << "2. Cap nhat thong tin\n"
             << "3. Tim khach hang theo ma\n"
             << "4. Hien thi danh sach\n"
             << "5. Xoa khach hang\n"
             << "0. Quay lai\n"
             << "Lua chon: ";

        if (!getline(cin, dongLuaChon)) {
            return;
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
            themKhachHang();
            break;
        case 2:
            capNhatKhachHang();
            break;
        case 3:
            timKiemKhachHang();
            break;
        case 4:
            hienThiDanhSachKhachHang();
            break;
        case 5:
            xoaKhachHang();
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void CONSOLEUI::menuQuanLyNhanVien() {
    int luaChon = -1;
    while (true) {
        string dongLuaChon;
        cout << "\n=== QUAN LY NHAN VIEN ===\n"
             << "1. Them nhan vien\n"
             << "2. Cap nhat thong tin\n"
             << "3. Tim nhan vien theo ma\n"
             << "4. Hien thi danh sach\n"
             << "5. Xoa nhan vien\n"
             << "0. Quay lai\n"
             << "Lua chon: ";

        if (!getline(cin, dongLuaChon)) {
            return;
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
            themNhanVien();
            break;
        case 2:
            capNhatNhanVien();
            break;
        case 3:
            timKiemNhanVien();
            break;
        case 4:
            hienThiDanhSachNhanVien();
            break;
        case 5:
            xoaNhanVien();
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void CONSOLEUI::menuQuanLyTaiXe() {
    int luaChon = -1;
    while (true) {
        string dongLuaChon;
        cout << "\n=== QUAN LY TAI XE ===\n"
             << "1. Them tai xe\n"
             << "2. Cap nhat thong tin\n"
             << "3. Tim tai xe theo ma\n"
             << "4. Hien thi danh sach\n"
             << "5. Xoa tai xe\n"
             << "0. Quay lai\n"
             << "Lua chon: ";

        if (!getline(cin, dongLuaChon)) {
            return;
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
            themTaiXe();
            break;
        case 2:
            capNhatTaiXe();
            break;
        case 3:
            timKiemTaiXe();
            break;
        case 4:
            hienThiDanhSachTaiXe();
            break;
        case 5:
            xoaTaiXe();
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void CONSOLEUI::menuQuanLyPhuongTien() {
    int luaChon = -1;
    while (true) {
        string dongLuaChon;
        cout << "\n=== QUAN LY PHUONG TIEN ===\n"
             << "1. Them phuong tien\n"
             << "2. Cap nhat thong tin\n"
             << "3. Tim phuong tien theo ma\n"
             << "4. Hien thi danh sach\n"
             << "5. Xoa phuong tien\n"
             << "0. Quay lai\n"
             << "Lua chon: ";

        if (!getline(cin, dongLuaChon)) {
            return;
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
            themPhuongTien();
            break;
        case 2:
            capNhatPhuongTien();
            break;
        case 3:
            timKiemPhuongTien();
            break;
        case 4:
            hienThiDanhSachPhuongTien();
            break;
        case 5:
            xoaPhuongTien();
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void CONSOLEUI::menuTimKiemVaThongKe() {
    int luaChon = -1;
    while (true) {
        string dongLuaChon;
        cout << "\n=== TIM KIEM VA THONG KE ===\n"
             << "1. Tim buu kien theo ma\n"
             << "2. Hien thi tat ca buu kien\n"
             << "3. Loc theo trang thai\n"
             << "4. Loc theo loai\n"
             << "5. Thong ke theo trang thai va loai\n"
             << "0. Quay lai\n"
             << "Lua chon: ";

        if (!getline(cin, dongLuaChon)) {
            return;
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
            timKiemBuuKien();
            break;
        case 2:
            hienThiDanhSach();
            break;
        case 3:
            locTheoTrangThai();
            break;
        case 4:
            locTheoLoai();
            break;
        case 5:
            thongKe();
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void CONSOLEUI::themBuuKien() {
    ThongTinBuuKien thongTin;

    if (!nhapThongTinBuuKien(thongTin)) return;

    switch (buuKienService.themBuuKien(thongTin)) {
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
    case KetQuaThemBuuKien::TRANG_THAI_KHONG_HOP_LE:
        cout << "Trang thai buu kien khong hop le.\n";
        break;
    case KetQuaThemBuuKien::LOI_LUU_TRU:
        cout << "Khong the luu buu kien.\n";
        break;
    }
}

void CONSOLEUI::timKiemBuuKien() const {
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
    if (!buuKienService.timBuuKienTheoMa(maBuuKien, ketQua)) {
        cout << "Khong tim thay buu kien co ma " << maBuuKien << ".\n";
        return;
    }

    hienThiThongTinBuuKien(ketQua, "KET QUA TIM KIEM");
}

void CONSOLEUI::capNhatBuuKien() {
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
    if (!buuKienService.timBuuKienTheoMa(maBuuKien, thongTin)) {
        cout << "Khong tim thay buu kien co ma " << maBuuKien << ".\n";
        return;
    }

    hienThiThongTinBuuKien(thongTin, "THONG TIN HIEN TAI");
    cout << "Nhap thong tin moi (ma buu kien se duoc giu nguyen):\n";
    if (!nhapThongTinBuuKien(thongTin)) {
        return;
    }

    switch (buuKienService.capNhatBuuKien(maBuuKien, thongTin)) {
    case KetQuaCapNhatBuuKien::THANH_CONG:
        cout << "Cap nhat buu kien thanh cong.\n";
        break;
    case KetQuaCapNhatBuuKien::KHONG_TIM_THAY:
        cout << "Khong tim thay buu kien de cap nhat.\n";
        break;
    case KetQuaCapNhatBuuKien::LOAI_KHONG_HOP_LE:
        cout << "Loai buu kien khong hop le.\n";
        break;
    case KetQuaCapNhatBuuKien::TRANG_THAI_KHONG_HOP_LE:
        cout << "Trang thai buu kien khong hop le.\n";
        break;
    case KetQuaCapNhatBuuKien::LOI_LUU_TRU:
        cout << "Khong the cap nhat buu kien.\n";
        break;
    }
}

void CONSOLEUI::huyBuuKien() {
    string maBuuKien;
    cout << "Nhap ma buu kien can huy: ";
    if (!getline(cin, maBuuKien)) {
        return;
    }
    if (maBuuKien.empty()) {
        cout << "Ma buu kien khong duoc de trong.\n";
        return;
    }

    switch (buuKienService.huyBuuKien(maBuuKien)) {
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

void CONSOLEUI::xoaBuuKien() {
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
    if (!buuKienService.timBuuKienTheoMa(maBuuKien, thongTin)) {
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

    switch (buuKienService.xoaBuuKien(maBuuKien)) {
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

void CONSOLEUI::hienThiDanhSach() const {
    const vector<ThongTinBuuKien> danhSach =
        buuKienService.layDanhSachBuuKien();
    hienThiDanhSachBuuKien(danhSach, "DANH SACH BUU KIEN");
}

void CONSOLEUI::locTheoTrangThai() const {
    string trangThai;
    cout << "Nhap trang thai can loc: ";
    if (!getline(cin, trangThai)) {
        return;
    }

    const string tieuChi = chuanHoaTieuChi(trangThai);
    if (tieuChi.empty()) {
        cout << "Trang thai khong duoc de trong.\n";
        return;
    }

    vector<ThongTinBuuKien> ketQua;
    for (const ThongTinBuuKien& buuKien :
         buuKienService.layDanhSachBuuKien()) {
        if (chuanHoaTieuChi(buuKien.trangThai) == tieuChi) {
            ketQua.push_back(buuKien);
        }
    }
    hienThiDanhSachBuuKien(
        ketQua, "KET QUA LOC TRANG THAI " + trangThai);
}

void CONSOLEUI::locTheoLoai() const {
    string loai;
    cout << "Nhap loai can loc (BINH_THUONG, HOA_TOC, NHANH): ";
    if (!getline(cin, loai)) {
        return;
    }

    const string tieuChi = chuanHoaTieuChi(loai);
    if (tieuChi != "BINH_THUONG"
        && tieuChi != "HOA_TOC"
        && tieuChi != "NHANH") {
        cout << "Loai buu kien khong hop le.\n";
        return;
    }

    vector<ThongTinBuuKien> ketQua;
    for (const ThongTinBuuKien& buuKien :
         buuKienService.layDanhSachBuuKien()) {
        if (chuanHoaTieuChi(buuKien.loaiBuuKien) == tieuChi) {
            ketQua.push_back(buuKien);
        }
    }
    hienThiDanhSachBuuKien(ketQua, "KET QUA LOC LOAI " + tieuChi);
}

void CONSOLEUI::thongKe() const {
    const vector<ThongTinBuuKien> danhSach =
        buuKienService.layDanhSachBuuKien();
    map<string, size_t> theoTrangThai;
    map<string, size_t> theoLoai;

    for (const ThongTinBuuKien& buuKien : danhSach) {
        const string trangThai = chuanHoaTieuChi(buuKien.trangThai);
        const string loai = chuanHoaTieuChi(buuKien.loaiBuuKien);
        ++theoTrangThai[trangThai.empty() ? "CHUA_CAP_NHAT" : trangThai];
        ++theoLoai[loai.empty() ? "CHUA_PHAN_LOAI" : loai];
    }

    cout << "\n=== THONG KE BUU KIEN ===\n"
         << "Tong so buu kien: " << danhSach.size() << '\n'
         << "Theo trang thai:\n";
    for (const auto& thongKeTrangThai : theoTrangThai) {
        cout << "  " << thongKeTrangThai.first << ": "
             << thongKeTrangThai.second << '\n';
    }

    cout << "Theo loai:\n";
    for (const auto& thongKeLoai : theoLoai) {
        cout << "  " << thongKeLoai.first << ": "
             << thongKeLoai.second << '\n';
    }
}

void CONSOLEUI::themKhachHang() {
    ThongTinKhachHang thongTin;
    if (!nhapThongTinKhachHang(thongTin)) {
        return;
    }

    switch (khachHangService.themKhachHang(thongTin)) {
    case KetQuaThemKhachHang::THANH_CONG:
        cout << "Them khach hang thanh cong. Ma khach hang: "
             << thongTin.maKhachHang << '\n';
        break;
    case KetQuaThemKhachHang::MA_TRONG:
        cout << "Khong tao duoc ma khach hang.\n";
        break;
    case KetQuaThemKhachHang::LOI_LUU_TRU:
        cout << "Khong the luu khach hang.\n";
        break;
    }
}

void CONSOLEUI::timKiemKhachHang() const {
    string maKhachHang;
    cout << "Nhap ma khach hang can tim: ";
    if (!getline(cin, maKhachHang)) {
        return;
    }
    if (maKhachHang.empty()) {
        cout << "Ma khach hang khong duoc de trong.\n";
        return;
    }

    ThongTinKhachHang ketQua;
    if (!khachHangService.timKhachHangTheoMa(maKhachHang, ketQua)) {
        cout << "Khong tim thay khach hang co ma "
             << maKhachHang << ".\n";
        return;
    }

    hienThiThongTinKhachHang(ketQua, "KET QUA TIM KIEM");
}

void CONSOLEUI::capNhatKhachHang() {
    string maKhachHang;
    cout << "Nhap ma khach hang can cap nhat: ";
    if (!getline(cin, maKhachHang)) {
        return;
    }
    if (maKhachHang.empty()) {
        cout << "Ma khach hang khong duoc de trong.\n";
        return;
    }

    ThongTinKhachHang thongTin;
    if (!khachHangService.timKhachHangTheoMa(maKhachHang, thongTin)) {
        cout << "Khong tim thay khach hang co ma "
             << maKhachHang << ".\n";
        return;
    }

    hienThiThongTinKhachHang(thongTin, "THONG TIN HIEN TAI");
    cout << "Nhap thong tin moi (ma khach hang se duoc giu nguyen):\n";
    if (!nhapThongTinKhachHang(thongTin)) {
        return;
    }

    switch (khachHangService.capNhatKhachHang(maKhachHang, thongTin)) {
    case KetQuaCapNhatKhachHang::THANH_CONG:
        cout << "Cap nhat khach hang thanh cong.\n";
        break;
    case KetQuaCapNhatKhachHang::KHONG_TIM_THAY:
        cout << "Khong tim thay khach hang de cap nhat.\n";
        break;
    case KetQuaCapNhatKhachHang::LOI_LUU_TRU:
        cout << "Khong the cap nhat khach hang.\n";
        break;
    }
}

void CONSOLEUI::xoaKhachHang() {
    string maKhachHang;
    cout << "Nhap ma khach hang can xoa: ";
    if (!getline(cin, maKhachHang)) {
        return;
    }
    if (maKhachHang.empty()) {
        cout << "Ma khach hang khong duoc de trong.\n";
        return;
    }

    ThongTinKhachHang thongTin;
    if (!khachHangService.timKhachHangTheoMa(maKhachHang, thongTin)) {
        cout << "Khong tim thay khach hang co ma "
             << maKhachHang << ".\n";
        return;
    }
    hienThiThongTinKhachHang(thongTin, "KHACH HANG SE BI XOA");

    string xacNhan;
    cout << "Nhap XOA de xac nhan xoa khach hang: ";
    if (!getline(cin, xacNhan) || xacNhan != "XOA") {
        cout << "Da huy thao tac xoa.\n";
        return;
    }

    switch (khachHangService.xoaKhachHang(maKhachHang)) {
    case KetQuaXuLyKhachHang::THANH_CONG:
        cout << "Da xoa khach hang.\n";
        break;
    case KetQuaXuLyKhachHang::KHONG_TIM_THAY:
        cout << "Khong tim thay khach hang de xoa.\n";
        break;
    case KetQuaXuLyKhachHang::LOI_LUU_TRU:
        cout << "Khong the xoa khach hang.\n";
        break;
    }
}

void CONSOLEUI::hienThiDanhSachKhachHang() const {
    inDanhSachKhachHang(khachHangService.layDanhSachKhachHang());
}

void CONSOLEUI::themNhanVien() {
    ThongTinNhanVien thongTin;
    if (!nhapThongTinNhanVien(thongTin)) {
        return;
    }

    switch (nhanVienService.themNhanVien(thongTin)) {
    case KetQuaThemNhanVien::THANH_CONG:
        cout << "Them nhan vien thanh cong. Ma nhan vien: "
             << thongTin.maNhanVien << '\n';
        break;
    case KetQuaThemNhanVien::MA_TRONG:
        cout << "Khong tao duoc ma nhan vien.\n";
        break;
    case KetQuaThemNhanVien::LOI_LUU_TRU:
        cout << "Khong the luu nhan vien.\n";
        break;
    }
}

void CONSOLEUI::timKiemNhanVien() const {
    string maNhanVien;
    cout << "Nhap ma nhan vien can tim: ";
    if (!getline(cin, maNhanVien)) {
        return;
    }
    if (maNhanVien.empty()) {
        cout << "Ma nhan vien khong duoc de trong.\n";
        return;
    }

    ThongTinNhanVien ketQua;
    if (!nhanVienService.timNhanVienTheoMa(maNhanVien, ketQua)) {
        cout << "Khong tim thay nhan vien co ma "
             << maNhanVien << ".\n";
        return;
    }

    hienThiThongTinNhanVien(ketQua, "KET QUA TIM KIEM");
}

void CONSOLEUI::capNhatNhanVien() {
    string maNhanVien;
    cout << "Nhap ma nhan vien can cap nhat: ";
    if (!getline(cin, maNhanVien)) {
        return;
    }
    if (maNhanVien.empty()) {
        cout << "Ma nhan vien khong duoc de trong.\n";
        return;
    }

    ThongTinNhanVien thongTin;
    if (!nhanVienService.timNhanVienTheoMa(maNhanVien, thongTin)) {
        cout << "Khong tim thay nhan vien co ma "
             << maNhanVien << ".\n";
        return;
    }

    hienThiThongTinNhanVien(thongTin, "THONG TIN HIEN TAI");
    cout << "Nhap thong tin moi (ma nhan vien se duoc giu nguyen):\n";
    if (!nhapThongTinNhanVien(thongTin)) {
        return;
    }

    switch (nhanVienService.capNhatNhanVien(maNhanVien, thongTin)) {
    case KetQuaCapNhatNhanVien::THANH_CONG:
        cout << "Cap nhat nhan vien thanh cong.\n";
        break;
    case KetQuaCapNhatNhanVien::KHONG_TIM_THAY:
        cout << "Khong tim thay nhan vien de cap nhat.\n";
        break;
    case KetQuaCapNhatNhanVien::LOI_LUU_TRU:
        cout << "Khong the cap nhat nhan vien.\n";
        break;
    }
}

void CONSOLEUI::xoaNhanVien() {
    string maNhanVien;
    cout << "Nhap ma nhan vien can xoa: ";
    if (!getline(cin, maNhanVien)) {
        return;
    }
    if (maNhanVien.empty()) {
        cout << "Ma nhan vien khong duoc de trong.\n";
        return;
    }

    ThongTinNhanVien thongTin;
    if (!nhanVienService.timNhanVienTheoMa(maNhanVien, thongTin)) {
        cout << "Khong tim thay nhan vien co ma "
             << maNhanVien << ".\n";
        return;
    }
    hienThiThongTinNhanVien(thongTin, "NHAN VIEN SE BI XOA");

    string xacNhan;
    cout << "Nhap XOA de xac nhan xoa nhan vien: ";
    if (!getline(cin, xacNhan) || xacNhan != "XOA") {
        cout << "Da huy thao tac xoa.\n";
        return;
    }

    switch (nhanVienService.xoaNhanVien(maNhanVien)) {
    case KetQuaXuLyNhanVien::THANH_CONG:
        cout << "Da xoa nhan vien.\n";
        break;
    case KetQuaXuLyNhanVien::KHONG_TIM_THAY:
        cout << "Khong tim thay nhan vien de xoa.\n";
        break;
    case KetQuaXuLyNhanVien::LOI_LUU_TRU:
        cout << "Khong the xoa nhan vien.\n";
        break;
    }
}

void CONSOLEUI::hienThiDanhSachNhanVien() const {
    inDanhSachNhanVien(nhanVienService.layDanhSachNhanVien());
}

void CONSOLEUI::themTaiXe() {
    ThongTinTaiXe thongTin;
    if (!nhapThongTinTaiXe(thongTin)) {
        return;
    }

    switch (taiXeService.themTaiXe(thongTin)) {
    case KetQuaThemTaiXe::THANH_CONG:
        cout << "Them tai xe thanh cong. Ma tai xe: "
             << thongTin.maTaiXe << '\n';
        break;
    case KetQuaThemTaiXe::MA_TRONG:
        cout << "Khong tao duoc ma tai xe.\n";
        break;
    case KetQuaThemTaiXe::LOI_LUU_TRU:
        cout << "Khong the luu tai xe.\n";
        break;
    }
}

void CONSOLEUI::timKiemTaiXe() const {
    string maTaiXe;
    cout << "Nhap ma tai xe can tim: ";
    if (!getline(cin, maTaiXe)) {
        return;
    }
    if (maTaiXe.empty()) {
        cout << "Ma tai xe khong duoc de trong.\n";
        return;
    }

    ThongTinTaiXe ketQua;
    if (!taiXeService.timTaiXeTheoMa(maTaiXe, ketQua)) {
        cout << "Khong tim thay tai xe co ma "
             << maTaiXe << ".\n";
        return;
    }

    hienThiThongTinTaiXe(ketQua, "KET QUA TIM KIEM");
}

void CONSOLEUI::capNhatTaiXe() {
    string maTaiXe;
    cout << "Nhap ma tai xe can cap nhat: ";
    if (!getline(cin, maTaiXe)) {
        return;
    }
    if (maTaiXe.empty()) {
        cout << "Ma tai xe khong duoc de trong.\n";
        return;
    }

    ThongTinTaiXe thongTin;
    if (!taiXeService.timTaiXeTheoMa(maTaiXe, thongTin)) {
        cout << "Khong tim thay tai xe co ma "
             << maTaiXe << ".\n";
        return;
    }

    hienThiThongTinTaiXe(thongTin, "THONG TIN HIEN TAI");
    cout << "Nhap thong tin moi (ma tai xe se duoc giu nguyen):\n";
    if (!nhapThongTinTaiXe(thongTin)) {
        return;
    }

    switch (taiXeService.capNhatTaiXe(maTaiXe, thongTin)) {
    case KetQuaCapNhatTaiXe::THANH_CONG:
        cout << "Cap nhat tai xe thanh cong.\n";
        break;
    case KetQuaCapNhatTaiXe::KHONG_TIM_THAY:
        cout << "Khong tim thay tai xe de cap nhat.\n";
        break;
    case KetQuaCapNhatTaiXe::LOI_LUU_TRU:
        cout << "Khong the cap nhat tai xe.\n";
        break;
    }
}

void CONSOLEUI::xoaTaiXe() {
    string maTaiXe;
    cout << "Nhap ma tai xe can xoa: ";
    if (!getline(cin, maTaiXe)) {
        return;
    }
    if (maTaiXe.empty()) {
        cout << "Ma tai xe khong duoc de trong.\n";
        return;
    }

    ThongTinTaiXe thongTin;
    if (!taiXeService.timTaiXeTheoMa(maTaiXe, thongTin)) {
        cout << "Khong tim thay tai xe co ma "
             << maTaiXe << ".\n";
        return;
    }
    hienThiThongTinTaiXe(thongTin, "TAI XE SE BI XOA");

    string xacNhan;
    cout << "Nhap XOA de xac nhan xoa tai xe: ";
    if (!getline(cin, xacNhan) || xacNhan != "XOA") {
        cout << "Da huy thao tac xoa.\n";
        return;
    }

    switch (taiXeService.xoaTaiXe(maTaiXe)) {
    case KetQuaXuLyTaiXe::THANH_CONG:
        cout << "Da xoa tai xe.\n";
        break;
    case KetQuaXuLyTaiXe::KHONG_TIM_THAY:
        cout << "Khong tim thay tai xe de xoa.\n";
        break;
    case KetQuaXuLyTaiXe::LOI_LUU_TRU:
        cout << "Khong the xoa tai xe.\n";
        break;
    }
}

void CONSOLEUI::hienThiDanhSachTaiXe() const {
    inDanhSachTaiXe(taiXeService.layDanhSachTaiXe());
}

void CONSOLEUI::themPhuongTien() {
    ThongTinPhuongTien thongTin = {};
    if (!nhapThongTinPhuongTien(thongTin)) {
        return;
    }

    switch (phuongTienService.themPhuongTien(thongTin)) {
    case KetQuaThemPhuongTien::THANH_CONG:
        cout << "Them phuong tien thanh cong. Ma phuong tien: "
             << thongTin.maPhuongTien << '\n';
        break;
    case KetQuaThemPhuongTien::MA_TRONG:
        cout << "Khong tao duoc ma phuong tien.\n";
        break;
    case KetQuaThemPhuongTien::LOI_LUU_TRU:
        cout << "Khong the luu phuong tien.\n";
        break;
    }
}

void CONSOLEUI::timKiemPhuongTien() const {
    string maPhuongTien;
    cout << "Nhap ma phuong tien can tim: ";
    if (!getline(cin, maPhuongTien)) {
        return;
    }
    if (maPhuongTien.empty()) {
        cout << "Ma phuong tien khong duoc de trong.\n";
        return;
    }

    ThongTinPhuongTien ketQua = {};
    if (!phuongTienService.timPhuongTienTheoMa(maPhuongTien, ketQua)) {
        cout << "Khong tim thay phuong tien co ma "
             << maPhuongTien << ".\n";
        return;
    }

    hienThiThongTinPhuongTien(ketQua, "KET QUA TIM KIEM");
}

void CONSOLEUI::capNhatPhuongTien() {
    string maPhuongTien;
    cout << "Nhap ma phuong tien can cap nhat: ";
    if (!getline(cin, maPhuongTien)) {
        return;
    }
    if (maPhuongTien.empty()) {
        cout << "Ma phuong tien khong duoc de trong.\n";
        return;
    }

    ThongTinPhuongTien thongTin = {};
    if (!phuongTienService.timPhuongTienTheoMa(
            maPhuongTien, thongTin)) {
        cout << "Khong tim thay phuong tien co ma "
             << maPhuongTien << ".\n";
        return;
    }

    hienThiThongTinPhuongTien(thongTin, "THONG TIN HIEN TAI");
    cout << "Nhap thong tin moi (ma phuong tien se duoc giu nguyen):\n";
    if (!nhapThongTinPhuongTien(thongTin)) {
        return;
    }

    switch (phuongTienService.capNhatPhuongTien(
        maPhuongTien, thongTin)) {
    case KetQuaCapNhatPhuongTien::THANH_CONG:
        cout << "Cap nhat phuong tien thanh cong.\n";
        break;
    case KetQuaCapNhatPhuongTien::KHONG_TIM_THAY:
        cout << "Khong tim thay phuong tien de cap nhat.\n";
        break;
    case KetQuaCapNhatPhuongTien::LOI_LUU_TRU:
        cout << "Khong the cap nhat phuong tien.\n";
        break;
    }
}

void CONSOLEUI::xoaPhuongTien() {
    string maPhuongTien;
    cout << "Nhap ma phuong tien can xoa: ";
    if (!getline(cin, maPhuongTien)) {
        return;
    }
    if (maPhuongTien.empty()) {
        cout << "Ma phuong tien khong duoc de trong.\n";
        return;
    }

    ThongTinPhuongTien thongTin = {};
    if (!phuongTienService.timPhuongTienTheoMa(
            maPhuongTien, thongTin)) {
        cout << "Khong tim thay phuong tien co ma "
             << maPhuongTien << ".\n";
        return;
    }
    hienThiThongTinPhuongTien(thongTin, "PHUONG TIEN SE BI XOA");

    string xacNhan;
    cout << "Nhap XOA de xac nhan xoa phuong tien: ";
    if (!getline(cin, xacNhan) || xacNhan != "XOA") {
        cout << "Da huy thao tac xoa.\n";
        return;
    }

    switch (phuongTienService.xoaPhuongTien(maPhuongTien)) {
    case KetQuaXuLyPhuongTien::THANH_CONG:
        cout << "Da xoa phuong tien.\n";
        break;
    case KetQuaXuLyPhuongTien::KHONG_TIM_THAY:
        cout << "Khong tim thay phuong tien de xoa.\n";
        break;
    case KetQuaXuLyPhuongTien::LOI_LUU_TRU:
        cout << "Khong the xoa phuong tien.\n";
        break;
    }
}

void CONSOLEUI::hienThiDanhSachPhuongTien() const {
    inDanhSachPhuongTien(
        phuongTienService.layDanhSachPhuongTien());
}
