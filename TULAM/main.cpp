#include "./Business/BuuKienService.h"
#include "./DataAccess/LinkedListBuuKienRepository.h"
#include "./Presentation/ConsoleUI.h"
#include "./DataAccess/FileBuuKien.h"
#include <iostream>

int main(){
    LinkedListBuuKienRepository repository;
    const string duongDanFile = "data/databuukien.txt";
    FileBuuKien fileBuuKien(duongDanFile);
    BuuKienService service(repository);
    ConsoleUI GiaoDien(service);

    if (!fileBuuKien.read(repository)) {
        cerr << "Khong doc duoc file: " << duongDanFile
             << "\nHay chay chuong trinh tu thu muc TULAM.\n";
        return 1;
    }

    GiaoDien.run();
    if (!fileBuuKien.save(repository)) {
        cerr << "Khong the luu file: " << duongDanFile << '\n';
        return 1;
    }
}