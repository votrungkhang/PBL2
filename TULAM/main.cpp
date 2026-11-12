#include "./Business/BuuKienService.h"
#include "./Business/KhachhangService.h"
#include "./Business/NhanVienService.h"
#include "./Business/TaiXeService.h"
#include "./Business/PhuongTienService.h"
#include "./DataAccess/LinkedListBuuKienRepository.h"
#include "./DataAccess/LinkedListKhachHangRepository.h"
#include "./DataAccess/LinkedListNhanVienRepository.h"
#include "./DataAccess/LinkedListTaiXeRepository.h"
#include "./DataAccess/LinkedListPhuongTienRepository.h"
#include "./Presentation/ConsoleUI.h"
#include "./DataAccess/FileBuuKien.h"
#include "./DataAccess/FileKhachHang.h"
#include "./DataAccess/FileNhanVien.h"
#include "./DataAccess/FileTaiXe.h"
#include "./DataAccess/FilePhuongTien.h"
#include <iostream>

int main(){
    LINKEDLISTBUUKIENREPOSITORY buuKienRepository;
    LINKEDLISTKHACHHANGREPOSITORY khachHangRepository;
    LINKEDLISTNHANVIENREPOSITORY nhanVienRepository;
    LINKEDLISTTAIXEREPOSITORY taiXeRepository;
    LINKEDLISTPHUONGTIENREPOSITORY phuongTienRepository;
    const string duongDanFile = "data/databuukien.txt";
    const string duongDanFileKhachHang = "data/datakhachhang.txt";
    const string duongDanFileNhanVien = "data/datanhanvien.txt";
    const string duongDanFileTaiXe = "data/datataixe.txt";
    const string duongDanFilePhuongTien = "data/dataphuongtien.txt";
    FILEBUUKIEN fileBuuKien(duongDanFile);
    FILEKHACHHANG fileKhachHang(duongDanFileKhachHang);
    FILENHANVIEN fileNhanVien(duongDanFileNhanVien);
    FILETAIXE fileTaiXe(duongDanFileTaiXe);
    FILEPHUONGTIEN filePhuongTien(duongDanFilePhuongTien);
    BUUKIENSERVICE buuKienService(buuKienRepository);
    KHACHHANGSERVICE khachHangService(khachHangRepository);
    NHANVIENSERVICE nhanVienService(nhanVienRepository);
    TAIXESERVICE taiXeService(taiXeRepository);
    PHUONGTIENSERVICE phuongTienService(phuongTienRepository);
    CONSOLEUI GiaoDien(
        buuKienService, khachHangService, nhanVienService, taiXeService,
        phuongTienService);

    if (!fileBuuKien.read(buuKienRepository)) {
        cerr << "Khong doc duoc file: " << duongDanFile
             << "\nHay chay chuong trinh tu thu muc TULAM.\n";
        return 1;
    }
    if (!fileKhachHang.read(khachHangRepository)) {
        cerr << "Khong doc duoc file: " << duongDanFileKhachHang
             << "\nHay chay chuong trinh tu thu muc TULAM.\n";
        return 1;
    }
    if (!fileNhanVien.read(nhanVienRepository)) {
        cerr << "Khong doc duoc file: " << duongDanFileNhanVien
             << "\nHay chay chuong trinh tu thu muc TULAM.\n";
        return 1;
    }
    if (!fileTaiXe.read(taiXeRepository)) {
        cerr << "Khong doc duoc file: " << duongDanFileTaiXe
             << "\nHay chay chuong trinh tu thu muc TULAM.\n";
        return 1;
    }
    if (!filePhuongTien.read(phuongTienRepository)) {
        cerr << "Khong doc duoc file: " << duongDanFilePhuongTien
             << "\nHay chay chuong trinh tu thu muc TULAM.\n";
        return 1;
    }

    GiaoDien.run();
    if (!fileBuuKien.save(buuKienRepository)) {
        cerr << "Khong the luu file: " << duongDanFile << '\n';
        return 1;
    }
    if (!fileKhachHang.save(khachHangRepository)) {
        cerr << "Khong the luu file: "
             << duongDanFileKhachHang << '\n';
        return 1;
    }
    if (!fileNhanVien.save(nhanVienRepository)) {
        cerr << "Khong the luu file: "
             << duongDanFileNhanVien << '\n';
        return 1;
    }
    if (!fileTaiXe.save(taiXeRepository)) {
        cerr << "Khong the luu file: "
             << duongDanFileTaiXe << '\n';
        return 1;
    }
    if (!filePhuongTien.save(phuongTienRepository)) {
        cerr << "Khong the luu file: "
             << duongDanFilePhuongTien << '\n';
        return 1;
    }
}