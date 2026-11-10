#include "ConsoleUI.h"

#include <iostream>
#include <limits>
#include <string>

ConsoleUI::ConsoleUI(BuuKienService& service)
    : service(service) {}

int ConsoleUI::run() {
    int luaChon = -1;
    while (luaChon != 0) {
        std::cout << "\n=== QUAN LY BUU KIEN ===\n"
                  << "1. Them buu kien\n"
                  << "2. Hien thi danh sach\n"
                  << "0. Thoat\n"
                  << "Lua chon: ";

        if (!(std::cin >> luaChon)) {
            if (std::cin.eof()) {
                return 0;
            }
            std::cout << "Lua chon khong hop le.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');

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
            std::cout << "Lua chon khong hop le.\n";
        }
    }
    return 0;
}

void ConsoleUI::themBuuKien() {
    std::string maBuuKien;
    int loaiBuuKien = 0;

    std::cout << "Nhap ma buu kien: ";
    std::getline(std::cin, maBuuKien);
    std::cout << "Loai (1: Binh thuong, 2: Hoa toc, 3: Nhanh): ";
    if (!(std::cin >> loaiBuuKien)) {
        std::cout << "Loai buu kien khong hop le.\n";
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n');

    switch (service.themBuuKien(maBuuKien, loaiBuuKien)) {
    case KetQuaThemBuuKien::THANH_CONG:
        std::cout << "Them buu kien thanh cong.\n";
        break;
    case KetQuaThemBuuKien::MA_TRONG:
        std::cout << "Ma buu kien khong duoc de trong.\n";
        break;
    case KetQuaThemBuuKien::MA_DA_TON_TAI:
        std::cout << "Ma buu kien da ton tai.\n";
        break;
    case KetQuaThemBuuKien::LOAI_KHONG_HOP_LE:
        std::cout << "Loai buu kien khong hop le.\n";
        break;
    case KetQuaThemBuuKien::LOI_LUU_TRU:
        std::cout << "Khong the luu buu kien.\n";
        break;
    }
}

void ConsoleUI::hienThiDanhSach() const {
    const std::vector<const BuuKien*> danhSach =
        service.layDanhSachBuuKien();
    if (danhSach.empty()) {
        std::cout << "Danh sach buu kien dang trong.\n";
        return;
    }

    for (const BuuKien* buuKien : danhSach) {
        std::cout << "Ma: " << buuKien->getMaBuuKien()
                  << " | Loai: " << buuKien->getLoai() << '\n';
    }
}
