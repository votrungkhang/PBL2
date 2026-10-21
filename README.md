# 📦 Ứng dụng quản lý bưu kiện

## 1. Giới thiệu đề tài

**Tên đề tài:** Xây dựng ứng dụng quản lý bưu kiện bằng C++ sử dụng lập trình hướng đối tượng (OOP) và cây tìm kiếm nhị phân (Binary Search Tree — BST).

Ứng dụng được xây dựng nhằm hỗ trợ quản lý thông tin bưu kiện tại bưu cục, bao gồm thông tin định danh, người gửi, người nhận, dịch vụ vận chuyển, cước phí và trạng thái xử lý.

Chương trình cung cấp các chức năng thêm, xóa, cập nhật, tìm kiếm, lọc và thống kê bưu kiện. Dữ liệu được lưu vào tệp để có thể khôi phục khi khởi động chương trình. Ngoài ra, hệ thống được định hướng phát triển chức năng đăng nhập, phân quyền người dùng và lựa chọn bưu kiện phù hợp khi xe vận chuyển đến.

Dự án sử dụng **C++**, kết hợp lập trình hướng đối tượng với cấu trúc dữ liệu BST để tổ chức và quản lý bưu kiện.

## 2. Mô tả bài toán

Trong hoạt động của một bưu cục, mỗi bưu kiện có các thông tin riêng biệt và trải qua nhiều trạng thái trong quá trình vận chuyển. Nhân viên cần có khả năng tra cứu, cập nhật và quản lý những thông tin này một cách thuận tiện.

Nếu dữ liệu được quản lý thủ công hoặc phân tán, việc tìm kiếm một bưu kiện cụ thể, kiểm tra các bưu kiện chưa giao thành công, thống kê số lượng theo từng loại dịch vụ và bảo toàn dữ liệu sau khi tắt chương trình có thể trở nên khó khăn.

Vì vậy, bài toán đặt ra là xây dựng một ứng dụng có khả năng:

- Quản lý tập trung thông tin của các bưu kiện.
- Hỗ trợ thêm, xóa và cập nhật thông tin bưu kiện.
- Tìm kiếm bưu kiện theo mã hoặc các tiêu chí khác.
- Lọc và thống kê danh sách bưu kiện theo yêu cầu.
- Lưu trữ và khôi phục dữ liệu bằng tệp.
- Phân biệt quyền sử dụng giữa Admin/Nhân viên và Khách hàng.
- Chuẩn bị nền tảng cho chức năng lựa chọn bưu kiện để xếp lên xe vận chuyển.

Trong phạm vi ban đầu, dự án tập trung xây dựng các chức năng quản lý cơ bản. Chức năng điều phối xe sẽ được phát triển sau khi cấu trúc dữ liệu và những nghiệp vụ chính đã hoạt động ổn định.

## 3. Mục tiêu đề tài

### 3.1. Mục tiêu tổng quát

Xây dựng một chương trình quản lý bưu kiện có cấu trúc rõ ràng, dễ bảo trì và mở rộng, đồng thời vận dụng các kiến thức về C++, lập trình hướng đối tượng, cấu trúc dữ liệu và thuật toán.

### 3.2. Mục tiêu cụ thể

1. Xây dựng lớp cơ sở `BuuKien` và các lớp kế thừa đại diện cho từng loại dịch vụ.
2. Sử dụng cây tìm kiếm nhị phân BST để quản lý bưu kiện theo mã định danh.
3. Cài đặt các thao tác thêm, xóa, sửa, tìm kiếm và duyệt cây.
4. Hỗ trợ lọc và thống kê dữ liệu.
5. Đọc dữ liệu khi khởi động và ghi dữ liệu khi chương trình kết thúc.
6. Xây dựng chức năng đăng nhập và phân quyền theo vai trò.
7. Định hướng phát triển thuật toán đề xuất bưu kiện cần vận chuyển khi xe đến.

## 4. Phạm vi thực hiện

### 4.1. Phiên bản cơ bản

- Quản lý thông tin bưu kiện.
- Xây dựng các lớp kế thừa theo loại dịch vụ.
- Cài đặt cây BST và những thao tác cơ bản.
- Tìm kiếm, lọc và thống kê dữ liệu.
- Đọc và ghi dữ liệu bằng tệp.
- Xây dựng khung đăng nhập và phân quyền.
- Sử dụng giao diện dòng lệnh (console) trong giai đoạn đầu.

### 4.2. Hướng phát triển sau

- Quản lý phương tiện và lịch xe vận chuyển.
- Lựa chọn bưu kiện phù hợp với tuyến đường và sức chứa của xe.
- Ưu tiên bưu kiện theo loại dịch vụ và thời hạn giao.
- Theo dõi lịch sử thay đổi trạng thái.
- Phát triển giao diện đồ họa hoặc tích hợp cơ sở dữ liệu.

## 5. Thông tin cần quản lý

### 5.1. Thông tin định danh

| Thuộc tính    | Tên biến dự kiến | Ý nghĩa                            |
| ------------- | ---------------- | ---------------------------------- |
| Mã bưu kiện   | `MaBK`           | Mã định danh duy nhất của bưu kiện |
| Ngày gửi      | `NgayGui`        | Ngày bưu kiện được tiếp nhận       |
| Loại bưu kiện | `LoaiBK`         | Loại dịch vụ vận chuyển            |
| Trạng thái    | `TrangThai`      | Tình trạng hiện tại của bưu kiện   |

Một số trạng thái dự kiến:

- Đã tiếp nhận.
- Đang vận chuyển.
- Đang giao.
- Đã giao thành công.
- Thất lạc.

Các giá trị trạng thái cần được thống nhất trong chương trình để tránh nhập nhiều cách viết khác nhau cho cùng một trạng thái.

### 5.2. Thông tin người gửi

| Thuộc tính    | Tên biến dự kiến | Ý nghĩa               |
| ------------- | ---------------- | --------------------- |
| Họ tên        | `TenNguoiGui`    | Tên người gửi         |
| Số điện thoại | `SDTNguoiGui`    | Số điện thoại liên hệ |
| Địa chỉ       | `DiaChiGui`      | Địa chỉ gửi bưu kiện  |

### 5.3. Thông tin người nhận

| Thuộc tính    | Tên biến dự kiến | Ý nghĩa               |
| ------------- | ---------------- | --------------------- |
| Họ tên        | `TenNguoiNhan`   | Tên người nhận        |
| Số điện thoại | `SDTNguoiNhan`   | Số điện thoại liên hệ |
| Địa chỉ       | `DiaChiNhan`     | Địa chỉ nhận bưu kiện |

### 5.4. Thông tin vận chuyển và cước phí

| Thuộc tính           | Tên biến dự kiến    | Ý nghĩa                     |
| -------------------- | ------------------- | --------------------------- |
| Khối lượng           | `KhoiLuong`         | Khối lượng bưu kiện         |
| Chiều dài            | `ChieuDai`          | Chiều dài bưu kiện          |
| Chiều rộng           | `ChieuRong`         | Chiều rộng bưu kiện         |
| Chiều cao            | `ChieuCao`          | Chiều cao bưu kiện          |
| Cước vận chuyển      | `CuocPhi`           | Chi phí vận chuyển          |
| Phí dịch vụ          | `PhiDichVu`         | Phụ phí dịch vụ nếu có      |
| Tổng tiền            | `TongTien`          | Tổng số tiền cần thanh toán |
| Hình thức thanh toán | `HinhThucThanhToan` | Phương thức thanh toán      |

Công thức tính cước sẽ được xác định trong quá trình triển khai. Đây là quy tắc mô phỏng phục vụ mục đích học tập, không mặc nhiên đại diện cho biểu phí của một đơn vị vận chuyển thực tế.

Cần xác định rõ khoản phí nào được lưu trực tiếp và khoản phí nào được tính từ các thuộc tính khác để tránh dữ liệu không nhất quán.

## 6. Thiết kế hướng đối tượng

### 6.1. Lớp cơ sở `BuuKien`

Lớp `BuuKien` biểu diễn những thuộc tính và hành vi chung của tất cả bưu kiện.

**Thuộc tính dự kiến:**

- Mã bưu kiện.
- Ngày gửi.
- Loại bưu kiện.
- Trạng thái.
- Thông tin người gửi.
- Thông tin người nhận.
- Khối lượng và kích thước.
- Thông tin cước phí.

**Hàm thành viên dự kiến:**

- `Nhap()`: nhập thông tin bưu kiện.
- `Xuat()`: xuất thông tin bưu kiện.
- `TinhCuocPhi()`: tính cước vận chuyển.
- `CapNhatTrangThai()`: cập nhật trạng thái.
- Các hàm getter và setter cần thiết.

Hàm `TinhCuocPhi()` được định hướng xây dựng dưới dạng hàm ảo thuần túy để mỗi lớp kế thừa cài đặt cách tính cước riêng. Lớp cơ sở cần có hàm hủy ảo nếu đối tượng dẫn xuất được quản lý thông qua con trỏ `BuuKien*`.

### 6.2. Các lớp kế thừa

Hệ thống gồm ba loại bưu kiện:

| Lớp             | Thuộc tính riêng dự kiến        | Ý nghĩa                                      |
| --------------- | ------------------------------- | -------------------------------------------- |
| `BuuKienThuong` | `ThoiGianDuKien`                | Thời gian giao hàng dự kiến                  |
| `BuuKienNhanh`  | `ThoiGianCamKet`, `PhuPhiNhanh` | Thời gian cam kết và phụ phí dịch vụ nhanh   |
| `BuuKienHoaToc` | `ThoiHanGiao`, `PhuPhiHoaToc`   | Thời hạn giao gấp và phụ phí dịch vụ hỏa tốc |

Các lớp này kế thừa từ `BuuKien`, sử dụng lại những thuộc tính chung và ghi đè hàm `TinhCuocPhi()` bằng từ khóa `override`.

Không khai báo lại các thuộc tính đã có ở lớp cơ sở nếu chúng có cùng ý nghĩa.

## 7. Cấu trúc dữ liệu: Cây tìm kiếm nhị phân BST

### 7.1. Lý do lựa chọn

Cây tìm kiếm nhị phân (Binary Search Tree — BST) được chọn làm cấu trúc dữ liệu chính để quản lý các bưu kiện theo `MaBK`.

Việc lựa chọn BST giúp dự án áp dụng kiến thức về con trỏ, cấu trúc dữ liệu động, đệ quy, duyệt cây và các thao tác tìm kiếm, thêm, xóa phần tử.

### 7.2. Quy tắc tổ chức cây

Mỗi nút trong cây chứa một bưu kiện và hai liên kết đến cây con trái, cây con phải.

Quy tắc sắp xếp:

- Nếu mã bưu kiện nhỏ hơn mã tại nút hiện tại, đi về cây con trái.
- Nếu mã bưu kiện lớn hơn mã tại nút hiện tại, đi về cây con phải.
- Nếu mã đã tồn tại, từ chối thêm bưu kiện trùng mã.

`MaBK` được sử dụng làm khóa của BST và phải duy nhất trong hệ thống.

### 7.3. Cấu trúc `Node`

Mỗi nút dự kiến có dạng:

```cpp
struct Node {
    BuuKien* data;
    Node* left;
    Node* right;

    Node(BuuKien* bk)
        : data(bk), left(nullptr), right(nullptr) {}
};
```

Trong đó:

- `data`: con trỏ đến đối tượng bưu kiện.
- `left`: con trỏ đến nút con trái.
- `right`: con trỏ đến nút con phải.

Cần thiết kế rõ quyền sở hữu bộ nhớ. Nếu lớp quản lý chịu trách nhiệm sở hữu các đối tượng bưu kiện, khi xóa nút hoặc hủy cây phải giải phóng đối tượng đúng cách. Cũng cần tránh sao chép nông cây BST.

### 7.4. Các thao tác trên BST

- Thêm bưu kiện theo mã.
- Tìm bưu kiện theo mã.
- Xóa bưu kiện theo mã.
- Duyệt cây để xuất danh sách.
- Đếm số lượng bưu kiện.
- Duyệt cây để lọc và thống kê theo các tiêu chí khác.

Duyệt LNR (trái – nút – phải) giúp xuất bưu kiện theo thứ tự tăng dần của khóa `MaBK`, nếu quy tắc so sánh khóa được thống nhất.

**Độ phức tạp:** BST có thể thực hiện các thao tác tìm kiếm, thêm và xóa trong thời gian trung bình `O(log n)` khi cây tương đối cân bằng. Trong trường hợp cây bị lệch, độ phức tạp có thể tăng lên `O(n)`.

## 8. Các nhóm chức năng

### Nhóm 1: Quản lý bưu kiện

#### 8.1. Thêm bưu kiện

1. Nhập thông tin bưu kiện.
2. Kiểm tra dữ liệu bắt buộc và tính hợp lệ.
3. Kiểm tra mã bưu kiện đã tồn tại hay chưa.
4. Tạo đối tượng thuộc đúng lớp dẫn xuất.
5. Thêm đối tượng vào BST nếu dữ liệu hợp lệ.
6. Thông báo kết quả.

#### 8.2. Xóa bưu kiện

1. Nhập mã bưu kiện cần xóa.
2. Tìm nút tương ứng trong BST.
3. Nếu tồn tại, xóa nút theo đúng quy tắc BST.
4. Giải phóng bộ nhớ theo thiết kế sở hữu.
5. Thông báo kết quả thao tác.

#### 8.3. Cập nhật thông tin

1. Tìm bưu kiện theo mã.
2. Hiển thị thông tin hiện tại.
3. Cho phép cập nhật các trường được phép thay đổi.
4. Kiểm tra dữ liệu mới.
5. Cập nhật thông tin và thông báo kết quả.

Nếu thay đổi `MaBK`, cần xóa bưu kiện khỏi cây rồi chèn lại theo mã mới để bảo toàn tính chất BST.

### Nhóm 2: Tìm kiếm, lọc và thống kê

#### 8.4. Tìm kiếm

Các tiêu chí tìm kiếm dự kiến:

- Theo mã bưu kiện.
- Theo trạng thái.
- Theo loại bưu kiện.
- Theo số điện thoại người gửi hoặc người nhận.
- Theo tên người gửi hoặc người nhận.

Tìm kiếm theo `MaBK` sử dụng BST. Với những tiêu chí khác, phiên bản cơ bản có thể duyệt cây và kiểm tra từng bưu kiện.

#### 8.5. Lọc dữ liệu

Hệ thống dự kiến có thể tạo danh sách theo các tiêu chí:

- Trạng thái bưu kiện.
- Loại dịch vụ.
- Khoảng ngày gửi.
- Khoảng khối lượng.
- Các bưu kiện chưa giao thành công.

#### 8.6. Thống kê

Một số kết quả thống kê dự kiến:

- Tổng số bưu kiện.
- Số lượng bưu kiện theo từng loại.
- Số lượng bưu kiện theo từng trạng thái.
- Tổng cước phí hoặc tổng tiền của các bưu kiện thỏa mãn điều kiện.

### Nhóm 3: Lưu trữ dữ liệu

#### 8.7. Đọc dữ liệu từ tệp

Khi khởi động chương trình:

1. Kiểm tra tệp dữ liệu.
2. Nếu tệp tồn tại, đọc các bản ghi.
3. Xác định loại bưu kiện của từng bản ghi.
4. Tạo đúng đối tượng thuộc lớp tương ứng.
5. Kiểm tra dữ liệu và mã trùng.
6. Thêm các bưu kiện hợp lệ vào BST.

Nếu tệp chưa tồn tại, chương trình có thể khởi tạo danh sách rỗng.

#### 8.8. Ghi dữ liệu vào tệp

Khi chương trình kết thúc bình thường:

1. Duyệt các bưu kiện đang được quản lý.
2. Ghi thông tin ra tệp theo định dạng thống nhất.
3. Kiểm tra kết quả ghi.
4. Thông báo nếu quá trình lưu thất bại.

Có thể sử dụng tệp văn bản có cấu trúc hoặc CSV. Nếu sử dụng CSV, cần xử lý trường chứa dấu phẩy, dấu xuống dòng hoặc ký tự đặc biệt.

Mật khẩu người dùng không nên được lưu dưới dạng văn bản thuần. Dữ liệu tài khoản cần có thiết kế lưu trữ và bảo vệ riêng.

### Nhóm 4: Bảo mật và phân quyền

Hệ thống dự kiến có hai nhóm giao diện/chức năng.

#### 8.9. Admin/Nhân viên

Các quyền dự kiến:

- Xem danh sách bưu kiện.
- Thêm, xóa và cập nhật thông tin.
- Tìm kiếm, lọc và thống kê.
- Thực hiện các thao tác quản lý được cấp quyền.

Quyền của Admin và Nhân viên có thể được tách riêng trong quá trình triển khai.

#### 8.10. Khách hàng

Các chức năng dự kiến:

- Đăng nhập.
- Tra cứu bưu kiện bằng mã và thông tin xác thực phù hợp.
- Xem thông tin vận chuyển được phép công khai.

Khách hàng không được tự ý thay đổi dữ liệu quản lý nội bộ.

Việc phân quyền cần được kiểm tra tại từng chức năng, không chỉ dựa vào việc hiển thị menu khác nhau.

### Nhóm 5: Thuật toán và sắp xếp — Chuẩn bị danh sách bưu kiện khi xe đến

Đây là chức năng định hướng phát triển sau khi các tính năng cơ bản đã ổn định.

Khi xe vận chuyển đến theo lịch, hệ thống sẽ đề xuất danh sách bưu kiện phù hợp để xếp lên xe.

Các tiêu chí có thể được xem xét:

- Trạng thái hiện tại của bưu kiện.
- Địa chỉ, khu vực hoặc tuyến vận chuyển.
- Loại dịch vụ và thời hạn giao.
- Khối lượng, kích thước và sức chứa của xe.
- Quy tắc ưu tiên và thứ tự xếp hàng.

Sau khi hệ thống đề xuất danh sách, nhân viên có thể kiểm tra và xác nhận trước khi cập nhật trạng thái bưu kiện.

**Phạm vi hiện tại:** chức năng điều phối xe chưa được triển khai trong phiên bản cơ bản. Thuật toán lựa chọn và sắp xếp sẽ được thiết kế sau khi các quy tắc nghiệp vụ được xác định cụ thể.

## 9. Lớp quản lý bưu kiện

Lớp `QuanLyBuuKien` chịu trách nhiệm quản lý BST và cung cấp các thao tác nghiệp vụ cho chương trình.

Các phương thức dự kiến:

```cpp
class QuanLyBuuKien {
private:
    Node* root;
    int soLuong;

public:
    QuanLyBuuKien();

    void ThemBuuKien(BuuKien* bk);
    bool XoaBuuKien(const string& maBK);
    bool SuaBuuKien(const string& maBK);

    BuuKien* TimBuuKien(const string& maBK);
    void XuatDanhSach();

    void LocTheoTrangThai(const string& trangThai);
    void LocTheoLoai(const string& loaiBK);
    void ThongKe();

    bool DocFile(const string& tenFile);
    bool GhiFile(const string& tenFile);

    int GetSoLuong() const;

    ~QuanLyBuuKien();
};
```

Đây là khung thiết kế dự kiến, chưa phải phần cài đặt hoàn chỉnh. Cần xác định rõ quy tắc trả về khi thao tác thất bại, quyền sở hữu con trỏ, cách cập nhật `soLuong` và cách xử lý lỗi tệp.

## 10. Quy tắc và ràng buộc dữ liệu

1. `MaBK` không được để trống và phải duy nhất.
2. Khối lượng và kích thước phải là số hợp lệ, không âm.
3. Số điện thoại nên được lưu dưới dạng chuỗi để giữ được số `0` ở đầu.
4. Loại bưu kiện và trạng thái cần sử dụng danh sách giá trị thống nhất.
5. Các trường bắt buộc phải được kiểm tra trước khi thêm hoặc cập nhật.
6. Cước phí và tổng tiền phải được tính theo công thức nhất quán.
7. Thao tác sửa, xóa và cập nhật trạng thái phải kiểm tra bưu kiện có tồn tại hay không.
8. Khi đọc tệp, bản ghi lỗi hoặc mã trùng cần được xử lý an toàn.
9. Chỉ người dùng có quyền phù hợp mới được thực hiện các thao tác thay đổi dữ liệu.
10. Khi ghi tệp thất bại, chương trình cần thông báo để người dùng biết dữ liệu có thể chưa được lưu.

## 11. Luồng hoạt động của chương trình

### 11.1. Khi khởi động

1. Khởi tạo đối tượng quản lý bưu kiện.
2. Đọc dữ liệu từ tệp và dựng lại BST.
3. Hiển thị màn hình đăng nhập.
4. Xác định vai trò người dùng.
5. Hiển thị các chức năng tương ứng với quyền được cấp.

### 11.2. Trong quá trình sử dụng

1. Người dùng chọn chức năng.
2. Chương trình kiểm tra quyền truy cập.
3. Nhận dữ liệu và kiểm tra tính hợp lệ.
4. Thực hiện thao tác trên BST.
5. Hiển thị kết quả.

### 11.3. Khi kết thúc

1. Ghi dữ liệu bưu kiện ra tệp.
2. Kiểm tra và thông báo kết quả lưu.
3. Giải phóng bộ nhớ.
4. Kết thúc chương trình.

## 12. Kiến thức áp dụng

Dự án vận dụng các kiến thức:

- **C++ cơ bản:** kiểu dữ liệu, hàm, chuỗi, điều kiện và vòng lặp.
- **Lập trình hướng đối tượng:** lớp, đối tượng, đóng gói, kế thừa và đa hình.
- **Con trỏ và quản lý bộ nhớ:** cấp phát, giải phóng bộ nhớ và con trỏ đối tượng.
- **Cấu trúc dữ liệu:** BST, duyệt cây, thêm, tìm kiếm và xóa nút.
- **Thuật toán:** tìm kiếm, lọc, thống kê và sắp xếp ở giai đoạn mở rộng.
- **Xử lý tệp:** đọc, ghi và xử lý lỗi.
- **Thiết kế phần mềm:** phân chia trách nhiệm giữa các lớp, tổ chức mã nguồn và phân quyền.

## 13. Tiêu chí đánh giá phiên bản cơ bản

Phiên bản cơ bản được xem là đạt yêu cầu khi:

- Quản lý được ba loại bưu kiện.
- Không cho phép thêm hai bưu kiện có cùng mã.
- Thêm, tìm kiếm và xóa bưu kiện trong BST đúng quy tắc.
- Cập nhật thông tin mà không làm sai tính chất BST.
- Xuất danh sách và lọc/thống kê đúng với dữ liệu.
- Dữ liệu đã lưu thành công được khôi phục khi khởi động lại.
- Các thao tác cần bảo vệ được kiểm tra quyền truy cập theo phạm vi đã cài đặt.
- Xử lý được mã không tồn tại, dữ liệu nhập sai và lỗi đọc/ghi tệp.
- Có hướng dẫn biên dịch và chạy chương trình.

## 14. Hướng phát triển

Sau khi hoàn thiện các chức năng cơ bản, dự án có thể được mở rộng theo các hướng:

- Sử dụng AVL hoặc cấu trúc cân bằng khác để cải thiện hiệu năng.
- Xây dựng chỉ mục để tìm kiếm nhanh theo nhiều tiêu chí.
- Hoàn thiện quản lý tài khoản và phân quyền.
- Phát triển giao diện đồ họa.
- Quản lý phương tiện, lịch xe và tuyến vận chuyển.
- Xây dựng thuật toán đề xuất bưu kiện cần xếp lên xe.
- Lưu lịch sử thay đổi trạng thái và lịch sử thao tác.
- Chuyển từ lưu trữ bằng tệp sang hệ quản trị cơ sở dữ liệu.

## 15. Kết luận

Đề tài **Ứng dụng quản lý bưu kiện** hướng đến xây dựng một chương trình C++ kết hợp lập trình hướng đối tượng và cây tìm kiếm nhị phân.

Hệ thống tập trung trước hết vào việc quản lý thông tin, tìm kiếm, lọc, thống kê và lưu trữ bưu kiện. Trên nền tảng đó, các chức năng đăng nhập, phân quyền và điều phối bưu kiện theo lịch xe sẽ được phát triển ở những giai đoạn tiếp theo.

Việc chia dự án thành các lớp và giai đoạn giúp chương trình dễ kiểm thử, bảo trì và mở rộng trong tương lai.
