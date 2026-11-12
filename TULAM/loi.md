# Ket qua review thu muc TULAM

Review chi doc, khong chinh sua ma nguon.

## Cac phat hien

1. **[P1] Co the crash khi file co loai buu kien khong hop le.**  
   Trong [FiileBuuKien.cpp](DataAccess/FiileBuuKien.cpp#L121), `taoBuuKien()` co the tra ve `nullptr`, nhung `read()` van goi `SetMaBuuKien()` tren ket qua do. Mot dong du lieu co loai khong nhan dien duoc co the lam chuong trinh dung khi khoi dong.

2. **[P2] Ky tu `|` hoac xuong dong trong truong chuoi lam hong dinh dang file.**  
   [save()](DataAccess/FiileBuuKien.cpp#L87) ghi cac truong chuoi truc tiep, trong khi bo doc yeu cau dung 14 truong. Neu dia chi hoac thoi gian chua ky tu phan cach, lan doc tiep theo co the that bai.

3. **[P2] Co the nap cac ma buu kien trung nhau.**  
   [read()](DataAccess/FiileBuuKien.cpp#L139) goi `add()` ma khong kiem tra ma da ton tai; [add()](DataAccess/LinkedListBuuKienRepository.cpp#L19) cung khong chan trung. Tim, cap nhat hoac xoa theo ma co the chi tac dong den ban ghi dau tien.

4. **[P2] Doc file khong kiem tra trang thai theo danh sach hop le.**  
   Service kiem tra trang thai khi them/cap nhat, nhung [read()](DataAccess/FiileBuuKien.cpp#L130) gan thang chuoi tu file. Hien [databuukien.txt](data/databuukien.txt#L1) co trang thai nam ngoai danh sach hop le, nen du lieu khong dong nhat sau khi khoi dong.

5. **[P2] Bo dem ma chua thuc su theo ngay va chua khoi phuc tu du lieu da luu.**  
   [BuuKienService](Business/BuuKienService.cpp#L115) khoi tao bo dem bang `0`. Khi them, service lay ngay hien tai de tao ma nhung khong reset bo dem theo ngay. Chay qua ngay moi van dung tiep so thu tu cu; sau khi khoi dong lai, bo dem cung khong phan anh cac ma da luu.

6. **[P2] Chua chan so lieu am hoac so khong hop le ve nghiep vu.**  
   [ConsoleUI.cpp](Presentation/ConsoleUI.cpp#L93) chi kiem tra nhap duoc so, nen can nang va cac khoan phi am van co the duoc chap nhan. Khi doc file, `stod()` tai [FiileBuuKien.cpp](DataAccess/FiileBuuKien.cpp#L125) co the chap nhan phan so dau cua chuoi nhu `12abc`.

7. **[P2] Luu file co nguy co lam mat ban cu neu ghi that bai giua chung.**  
   [save()](DataAccess/FiileBuuKien.cpp#L78) mo file o che do ghi de truoc khi hoan tat ghi du lieu. Neu ghi loi, file cu da bi cat va file moi co the chi chua du lieu mot phan.

## Kiem tra

- Bien dich lien ket ca 9 file C++ thanh cong voi `-Wall -Wextra -Wpedantic`.
- Khong thay canh bao tu lenh kiem tra.
