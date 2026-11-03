#include"dslk.h"
#include"BuuKienBinhThuong.h"
#include"BuuKienHoaToc.h"
#include"BuuKienNhanh.h"
#include"QuanLy.h"
int main() {
    LinkedList list;
    QuanLy QuanLyBuuKien(list);
    QuanLyBuuKien.themBuuKien();
    QuanLyBuuKien.Show();
    return 0;
}
