# Thuộc tính các đối tượng — Ứng dụng quản lý bưu kiện

> Ngôn ngữ: C++  
> Mục tiêu: quản lý bưu kiện, khách hàng, nhân viên, tài xế, phương tiện và chuyến vận chuyển.  
> Ghi chú: Đây là bản thiết kế đề xuất; các thuộc tính có thể điều chỉnh theo yêu cầu cuối cùng của giảng viên.

## 1. `BuuKien` — lớp cơ sở trừu tượng

Lưu những thông tin chung của tất cả các loại bưu kiện.

| Thuộc tính | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `maBuuKien` | `string` | Mã định danh duy nhất của bưu kiện |
| `trongLuong` | `double` | Trọng lượng bưu kiện |
| `diaChiGui` | `string` | Địa chỉ gửi |
| `diaChiNhan` | `string` | Địa chỉ nhận |
| `ngayGui` | `string` | Ngày tiếp nhận/gửi bưu kiện |
| `trangThai` | `TrangThaiBuuKien` hoặc `string` | Trạng thái hiện tại |
| `maNguoiGui` | `string` | Mã khách hàng đóng vai trò người gửi |
| `maNguoiNhan` | `string` | Mã khách hàng đóng vai trò người nhận |
| `maNhanVienTiepNhan` | `string` | Mã nhân viên tiếp nhận bưu kiện |
| `maChuyen` | `string` | Mã chuyến vận chuyển mà bưu kiện thuộc về |
| `phiDichVu` | `double` | Phí dịch vụ của bưu kiện, nếu cần lưu trực tiếp |

**Lưu ý:**
- `maNguoiGui` và `maNguoiNhan` là hai liên kết riêng biệt đến `KhachHang`. Một khách hàng có thể xuất hiện ở cả hai vai trò.
- `maNhanVienTiepNhan` và `maChuyen` là mã liên kết đến đối tượng tương ứng.
- Nếu `phiDichVu` được tính khác nhau theo từng loại dịch vụ, có thể đặt thuộc tính này ở lớp cơ sở nhưng để các lớp con tính toán bằng hàm ảo, thay vì lưu trùng nhiều nơi.
- Có thể dùng `enum class` cho trạng thái để hạn chế giá trị nhập sai.

## 2. Các lớp kế thừa từ `BuuKien`

### 2.1. `BuuKienHoaToc`

Kế thừa các thuộc tính chung từ `BuuKien`.

| Thuộc tính riêng | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `thoiGianGiaoDuKien` | `string` | Thời gian dự kiến giao |
| `phuPhiHoaToc` | `double` | Phụ phí hỏa tốc |

### 2.2. `BuuKienNhanh`

Kế thừa các thuộc tính chung từ `BuuKien`.

| Thuộc tính riêng | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `thoiGianGiaoDuKien` | `string` | Thời gian dự kiến giao |
| `phuPhiNhanh` | `double` | Phụ phí chuyển phát nhanh |

### 2.3. `BuuKienBinhThuong`

Kế thừa các thuộc tính chung từ `BuuKien`.

| Thuộc tính riêng | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `thoiGianGiaoDuKien` | `string` | Thời gian dự kiến giao |
| `phuPhiDichVu` | `double` | Phí/phụ phí của dịch vụ thường, nếu có |

> Không bắt buộc phải đặt tên phí khác nhau ở từng lớp. Nếu cùng một ý nghĩa nghiệp vụ, có thể dùng chung một thuộc tính `phiDichVu` ở lớp cơ sở và ghi đè hàm tính phí ở các lớp con.

## 3. `KhachHang`

Đại diện cho người gửi hoặc người nhận bưu kiện.

| Thuộc tính | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `maKhachHang` | `string` | Mã khách hàng |
| `hoTen` | `string` | Họ và tên |
| `sdt` | `string` | Số điện thoại |
| `diaChi` | `string` | Địa chỉ liên hệ |

Không cần lưu riêng hai danh sách bưu kiện gửi và nhận bên trong `KhachHang` nếu hệ thống có thể tra cứu từ các mã `maNguoiGui` và `maNguoiNhan` trong `BuuKien`.

## 4. `NhanVien`

Đại diện cho nhân viên bưu cục.

| Thuộc tính | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `maNhanVien` | `string` | Mã nhân viên |
| `hoTen` | `string` | Họ và tên |
| `chucVu` | `string` | Chức vụ, ví dụ nhân viên hoặc quản lý |
| `sdt` | `string` | Số điện thoại |

Nếu phân quyền bằng tài khoản riêng, thông tin đăng nhập nên được quản lý bởi lớp `TaiKhoan`, không nên lưu mật khẩu trực tiếp trong `NhanVien`.

## 5. `TaiXe`

Đại diện cho tài xế phụ trách các chuyến vận chuyển.

| Thuộc tính | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `maTaiXe` | `string` | Mã tài xế |
| `hoTen` | `string` | Họ và tên |
| `sdt` | `string` | Số điện thoại |
| `bangLai` | `string` | Hạng bằng lái |

## 6. `PhuongTien`

Đại diện cho phương tiện dùng để vận chuyển bưu kiện.

| Thuộc tính | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `maPhuongTien` | `string` | Mã phương tiện |
| `bienSo` | `string` | Biển số xe |
| `loaiXe` | `string` | Loại phương tiện |
| `taiTrongToiDa` | `double` | Tải trọng tối đa |
| `trangThai` | `TrangThaiPhuongTien` hoặc `string` | Trạng thái phương tiện, ví dụ sẵn sàng/bảo trì |

## 7. `ChuyenVanChuyen`

Đại diện cho một lần vận chuyển cụ thể. Theo mô hình hiện tại, mỗi chuyến có một tài xế, một phương tiện và nhiều bưu kiện; mỗi bưu kiện chỉ thuộc một chuyến.

| Thuộc tính | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `maChuyen` | `string` | Mã chuyến vận chuyển |
| `ngayVanChuyen` | `string` | Ngày/giờ dự kiến hoặc thực hiện chuyến |
| `diaChiXuatPhat` | `string` | Điểm xuất phát |
| `diaChiDen` | `string` | Điểm đến |
| `maTaiXe` | `string` | Mã tài xế phụ trách |
| `maPhuongTien` | `string` | Mã phương tiện sử dụng |
| `trangThai` | `TrangThaiChuyen` hoặc `string` | Trạng thái chuyến |
| `dsBuuKien` | Cấu trúc dữ liệu tự cài đặt chứa `BuuKien*` | Danh sách bưu kiện thuộc chuyến |

### Cách quản lý `dsBuuKien`

- `dsBuuKien` là thuộc tính cần có để chuyến biết những bưu kiện nào sẽ được vận chuyển.
- Nếu dùng `BuuKien**`, cần có thêm `soLuongBuuKien` và có thể cần `dungLuong` nếu mảng được cấp phát động.
- Nên để thành phần quản lý bưu kiện sở hữu các đối tượng `BuuKien`; `ChuyenVanChuyen` chỉ lưu con trỏ tham chiếu đến chúng. Khi xóa chuyến, không tự động `delete` các bưu kiện.
- Khi lưu dữ liệu ra tệp, nên ghi các `maBuuKien` của chuyến thay vì ghi lại toàn bộ nội dung đối tượng bưu kiện. Khi đọc dữ liệu, dùng mã để liên kết lại các đối tượng trong bộ nhớ.
- Nếu dự án yêu cầu tự cài đặt cấu trúc dữ liệu, `dsBuuKien` có thể là một danh sách liên kết hoặc cấu trúc tự viết khác; không bắt buộc dùng `std::vector`.

## 8. `TaiKhoan` — lớp đề xuất để đăng nhập và phân quyền

Lớp này là đề xuất bổ sung nếu hệ thống cần quản lý đăng nhập độc lập với thông tin nhân viên/khách hàng.

| Thuộc tính | Kiểu C++ gợi ý | Ý nghĩa |
|---|---|---|
| `tenDangNhap` | `string` | Tên đăng nhập duy nhất |
| `matKhauHash` | `string` | Giá trị băm mật khẩu; không lưu mật khẩu dạng rõ trong ứng dụng thực tế |
| `vaiTro` | `VaiTro` hoặc `string` | `ADMIN`, `NHAN_VIEN` hoặc `KHACH_HANG` |
| `maDoiTuong` | `string` | Mã nhân viên hoặc khách hàng được tài khoản liên kết |
| `trangThai` | `bool` hoặc `string` | Tài khoản đang hoạt động hay bị khóa |

Với đồ án console nhỏ, có thể triển khai đơn giản hơn theo yêu cầu môn học, nhưng nên tách thông tin tài khoản khỏi thông tin cá nhân.

## 9. Tóm tắt quan hệ giữa các đối tượng

- `BuuKien` là lớp cơ sở trừu tượng; ba lớp loại bưu kiện kế thừa từ lớp này.
- `KhachHang` — `BuuKien`: hai quan hệ riêng 1–N, lần lượt theo vai trò người gửi và người nhận.
- `NhanVien` — `BuuKien`: 1–N theo giả định mỗi bưu kiện có một nhân viên tiếp nhận ban đầu.
- `TaiXe` — `ChuyenVanChuyen`: 1–N.
- `PhuongTien` — `ChuyenVanChuyen`: 1–N.
- `ChuyenVanChuyen` — `BuuKien`: 1–N theo giả định mỗi bưu kiện chỉ thuộc một chuyến.
- `TaiKhoan` liên kết đến một đối tượng nhân viên hoặc khách hàng tùy vai trò; Admin có thể là tài khoản quản trị riêng.

## 10. Một số quyết định cần chốt trước khi lập trình

1. Mỗi bưu kiện chỉ có một chuyến hay có thể qua nhiều chuyến trung chuyển? Bản thiết kế này đang chọn **một bưu kiện thuộc một chuyến**.
2. Trạng thái bưu kiện, chuyến và phương tiện nên dùng `enum class` để quản lý các giá trị hợp lệ.
3. Chọn thống nhất kiểu ngày giờ; `string` dễ triển khai ban đầu nhưng cần định dạng cố định.
4. Xác định rõ đối tượng nào sở hữu bộ nhớ và đối tượng nào chỉ giữ con trỏ tham chiếu, nhất là với `BuuKien*` trong `ChuyenVanChuyen`.
5. Chỉ lưu một nguồn dữ liệu chính cho mỗi thông tin để tránh dữ liệu bị lệch giữa các tệp.
