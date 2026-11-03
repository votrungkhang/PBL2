# PBL2 — QUẢN LÝ SINH VIÊN

## 1. Tổng quan dự án

### Mục tiêu

Xây dựng phần mềm quản lý sinh viên bằng C++, vận dụng kiến thức của hai môn:

- Lập trình hướng đối tượng (OOP).
- Cấu trúc dữ liệu và giải thuật (DSA).

Hệ thống không chỉ quản lý sinh viên mà còn có thể quản lý các đối tượng khác như học phần và lớp học phần.

### Kiến trúc tổng thể

Dự án được chia thành 3 phần chính:

1. **DATA:** Lưu trữ dữ liệu trong các file `.txt`.
2. **OOP:** Xử lý dữ liệu, quản lý đối tượng và nghiệp vụ; gồm DAL và BLL.
3. **GUI:** Giao diện để người dùng tương tác với hệ thống.

Luồng xử lý tổng quát:

`GUI → BLL → DAL → File dữ liệu`

Kết quả xử lý được trả ngược lại để GUI hiển thị.

---

## 2. Phần DATA — Lưu trữ dữ liệu

### Nhiệm vụ

- Lưu dữ liệu lâu dài trong các file `.txt`.
- Đảm bảo dữ liệu có thể được sử dụng lại khi khởi động chương trình.
- Lưu thông tin của các đối tượng như sinh viên, học phần và lớp học phần.

Ví dụ cấu trúc thư mục:

```text
data/
├── SinhVien.txt
├── HocPhan.txt
└── LopHocPhan.txt
```

File dữ liệu chỉ đóng vai trò lưu trữ, không trực tiếp thực hiện các thuật toán quản lý trong bộ nhớ.

---

## 3. Phần OOP — Phân chia DAL và BLL

### 3.1. DAL — Data Access Layer

DAL chịu trách nhiệm truy cập dữ liệu từ file.

Các nhiệm vụ chính:

- Đọc dữ liệu từ file.
- Chuyển dữ liệu thành các đối tượng tương ứng.
- Cung cấp dữ liệu cho BLL.
- Ghi dữ liệu từ chương trình xuống file.

Ví dụ lớp:

```cpp
class SinhVienDAL {
public:
    // Đọc dữ liệu sinh viên từ file.
    // Ghi dữ liệu sinh viên xuống file.
};
```

DAL không chịu trách nhiệm thực hiện toàn bộ nghiệp vụ quản lý sinh viên.

### 3.2. BLL — Business Logic Layer

BLL chịu trách nhiệm quản lý dữ liệu trong bộ nhớ và xử lý nghiệp vụ.

Các nhiệm vụ chính:

- Quản lý sinh viên, học phần và lớp học phần.
- Thực hiện các thao tác CRUD.
- Kiểm tra tính hợp lệ của dữ liệu.
- Tìm kiếm, lọc, sắp xếp và thống kê.
- Sử dụng cấu trúc dữ liệu tự cài đặt.
- Gọi DAL để đọc hoặc ghi dữ liệu khi cần.

Để tránh trùng lặp code giữa các loại đối tượng, dự án dự kiến sử dụng một lớp quản lý tổng quát bằng Template.

---

## 4. Thiết kế lớp quản lý tổng quát bằng Template

### 4.1. Mục tiêu

Thay vì tạo nhiều lớp có cách quản lý dữ liệu giống nhau:

- `QuanLySinhVien`
- `QuanLyHocPhan`
- `QuanLyLopHocPhan`

Ta xây dựng một lớp tổng quát:

```cpp
template <typename T>
class QuanLy {
    // Cấu trúc dữ liệu và thao tác quản lý T.
};
```

Trong đó:

- `template`: Khai báo khuôn mẫu.
- `typename T`: Khai báo tham số kiểu dữ liệu.
- `T`: Kiểu dữ liệu mà lớp sẽ quản lý.

Có thể sử dụng lớp này cho nhiều kiểu dữ liệu:

```cpp
QuanLy<SinhVien> qlSinhVien;
QuanLy<HocPhan> qlHocPhan;
QuanLy<LopHocPhan> qlLopHocPhan;
```

Mỗi cách sử dụng tạo thành một phiên bản lớp tương ứng với kiểu dữ liệu cụ thể.

### 4.2. Trách nhiệm của lớp `QuanLy<T>`

Lớp quản lý tổng quát dự kiến đảm nhiệm:

- Chứa cấu trúc dữ liệu để lưu trữ đối tượng.
- Thêm đối tượng.
- Tìm kiếm đối tượng.
- Xóa đối tượng.
- Duyệt và lấy danh sách đối tượng.

Các thao tác trên cần được thiết kế phù hợp với cấu trúc dữ liệu được lựa chọn.

---

## 5. Tích hợp cấu trúc dữ liệu và giải thuật

### 5.1. Lựa chọn cấu trúc dữ liệu

Dự án có thể sử dụng cây tìm kiếm nhị phân (BST) tự cài đặt.

Ví dụ cấu trúc:

```cpp
template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
};
```

Cây BST tổng quát cần có:

- Con trỏ `root` quản lý nút gốc.
- Thuật toán thêm nút.
- Thuật toán tìm kiếm.
- Thuật toán xóa nút.
- Thuật toán duyệt cây.

### 5.2. Quan hệ giữa `QuanLy<T>` và BST

Lớp `QuanLy<T>` có thể chứa một đối tượng BST:

```cpp
template <typename T>
class QuanLy {
private:
    BST<T> cay;

public:
    // Các phương thức quản lý dữ liệu.
};
```

Trong thiết kế này:

- `BST<T>` chịu trách nhiệm cài đặt thuật toán và duy trì cấu trúc cây.
- `QuanLy<T>` sử dụng BST để thực hiện các thao tác quản lý dữ liệu.

Hai lớp có trách nhiệm riêng biệt, giúp dễ kiểm thử và bảo trì.

### 5.3. Lưu ý về khóa tìm kiếm

Mỗi loại đối tượng có thể sử dụng một thuộc tính định danh khác nhau:

- Sinh viên: `maSV`.
- Học phần: `maHP`.
- Lớp học phần: `maLHP`.

Do đó, BST tổng quát cần có cách xác định khóa và so sánh đối tượng phù hợp với kiểu `T`. Không nên mặc định mọi đối tượng đều có thuộc tính `maSV`.

---

## 6. Kết hợp kế thừa và đa hình

### 6.1. Mục tiêu

Các lớp quản lý chuyên biệt có thể kế thừa lớp quản lý tổng quát để bổ sung nghiệp vụ riêng.

Ví dụ:

- `QLSinhVien`
- `QLHocPhan`
- `QLLopHocPhan`

Khi cần đa hình, lớp cơ sở có thể khai báo phương thức `virtual` và lớp dẫn xuất ghi đè bằng `override`.

Ví dụ minh họa:

```cpp
template <typename T>
class QuanLy {
public:
    virtual void HienThiThongTin() = 0;

    virtual ~QuanLy() = default;
};
```

Lớp quản lý sinh viên:

```cpp
class QLSinhVien : public QuanLy<SinhVien> {
public:
    void HienThiThongTin() override {
        // Hiển thị thông tin quản lý sinh viên.
    }
};
```

Lớp quản lý học phần:

```cpp
class QLHocPhan : public QuanLy<HocPhan> {
public:
    void HienThiThongTin() override {
        // Hiển thị thông tin quản lý học phần.
    }
};
```

Đây là ví dụ về phương thức đa hình, không phải thiết kế hoàn chỉnh của lớp quản lý.

### 6.2. Nguyên tắc sử dụng

- **Template:** Tái sử dụng code cho nhiều kiểu dữ liệu.
- **Kế thừa:** Mở rộng lớp cơ sở để bổ sung hành vi.
- **Đa hình:** Cho phép lớp dẫn xuất cung cấp cách thực hiện riêng thông qua phương thức `virtual`.
- Không cần override những phương thức đã dùng chung và hoạt động đúng.
- Không nên đưa mọi nghiệp vụ đặc thù vào lớp quản lý tổng quát.

Lưu ý: `QuanLy<SinhVien>` và `QuanLy<HocPhan>` là hai kiểu khác nhau. Đa hình thông qua con trỏ lớp cơ sở chỉ áp dụng trong hệ phân cấp kiểu tương ứng, trừ khi có thêm một lớp cơ sở không phụ thuộc tham số Template.

---

## 7. Phần GUI — Giao diện người dùng

GUI chịu trách nhiệm:

- Hiển thị danh sách đối tượng.
- Nhận dữ liệu nhập từ người dùng.
- Cung cấp các nút thêm, sửa, xóa và tìm kiếm.
- Gọi BLL để xử lý yêu cầu.
- Hiển thị kết quả và thông báo lỗi.

GUI không nên trực tiếp thao tác với `root`, các nút của BST hoặc tự đọc và ghi file.

### Ví dụ luồng thêm sinh viên

1. Người dùng nhập thông tin trên GUI.
2. GUI gọi phương thức thêm sinh viên của BLL.
3. BLL kiểm tra dữ liệu hợp lệ.
4. BLL yêu cầu lớp quản lý tổng quát thêm đối tượng.
5. Lớp quản lý gọi BST để thực hiện thuật toán thêm.
6. BLL phối hợp với DAL để lưu trạng thái mới xuống file.
7. GUI nhận kết quả và cập nhật giao diện.

---

## 8. Nguyên tắc đồng bộ dữ liệu

Cần phân biệt hai nơi lưu dữ liệu:

- **File:** Lưu trữ lâu dài.
- **Cấu trúc dữ liệu trong bộ nhớ:** Phục vụ tìm kiếm, thêm, sửa, xóa và các thuật toán.

Một hướng thiết kế đơn giản:

1. Khi khởi động, DAL đọc file.
2. BLL nhận dữ liệu và xây dựng cấu trúc dữ liệu trong bộ nhớ.
3. Mọi thao tác quản lý được thực hiện thông qua BLL.
4. Sau khi thao tác thành công, hệ thống lưu trạng thái mới xuống file thông qua DAL.
5. Khi khởi động lại, cấu trúc dữ liệu được tạo lại từ dữ liệu trong file.

Cần tránh duy trì nhiều bản dữ liệu độc lập mà không có cơ chế đồng bộ.

---

## 9. Lộ trình triển khai

### Giai đoạn 1: Xây dựng mô hình dữ liệu

- Xây dựng lớp `SinhVien`.
- Xây dựng lớp `HocPhan`.
- Xây dựng lớp `LopHocPhan`.
- Xác định thuộc tính định danh của từng đối tượng.

### Giai đoạn 2: Xây dựng cấu trúc dữ liệu

- Tự cài đặt `Node<T>`.
- Xây dựng `BST<T>`.
- Cài đặt thêm, tìm kiếm, xóa và duyệt cây.
- Kiểm thử BST độc lập trước khi tích hợp.

### Giai đoạn 3: Xây dựng lớp quản lý tổng quát

- Xây dựng `QuanLy<T>`.
- Sử dụng BST để quản lý dữ liệu.
- Xác định cách truyền khóa và so sánh các kiểu đối tượng.
- Kiểm thử với nhiều kiểu dữ liệu.

### Giai đoạn 4: Xây dựng DAL

- Đọc dữ liệu từ file.
- Chuyển dữ liệu thành các đối tượng.
- Ghi dữ liệu xuống file.
- Kiểm thử việc lưu và nạp lại dữ liệu.

### Giai đoạn 5: Hoàn thiện BLL

- Tích hợp DAL với lớp quản lý tổng quát.
- Bổ sung các quy tắc nghiệp vụ.
- Tạo lớp quản lý chuyên biệt nếu cần.
- Sử dụng kế thừa và đa hình ở những vị trí hợp lý.

### Giai đoạn 6: Xây dựng GUI

- Thiết kế giao diện.
- Kết nối GUI với BLL.
- Kiểm thử toàn bộ luồng xử lý.

---

## 10. Tổng kết kiến trúc

| Thành phần              | Trách nhiệm chính                         |
| ----------------------- | ----------------------------------------- |
| DATA                    | Lưu dữ liệu lâu dài                       |
| DAL                     | Đọc và ghi file                           |
| BLL                     | Xử lý nghiệp vụ và điều phối thao tác     |
| `QuanLy<T>`             | Quản lý tổng quát cho nhiều kiểu dữ liệu  |
| `BST<T>`                | Cài đặt cấu trúc cây và thuật toán        |
| Lớp quản lý chuyên biệt | Bổ sung nghiệp vụ riêng, override khi cần |
| GUI                     | Tương tác với người dùng                  |

**Nguyên tắc thiết kế cốt lõi:** Mỗi lớp có một trách nhiệm rõ ràng; Template dùng để tái sử dụng code, BST để tổ chức dữ liệu, kế thừa và đa hình để mở rộng hành vi, còn DAL và GUI đảm nhiệm việc truy cập dữ liệu và tương tác người dùng.
