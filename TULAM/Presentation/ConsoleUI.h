#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "../Business/BuuKienService.h"

class ConsoleUI {
private:
    BuuKienService& service;

    void themBuuKien();
    void hienThiDanhSach() const;

public:
    ConsoleUI(BuuKienService& service);
    int run();
};

#endif
