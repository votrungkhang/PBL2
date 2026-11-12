#include <algorithm>
#include <cctype>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <utility>

#include "BuuKienService.h"
#include "IBuuKienRepository.h"
#include "../Domain/BuuKienBinhThuong.h"
#include "../Domain/BuuKienHoaToc.h"
#include "../Domain/BuuKienNhanh.h"

namespace {
string chuanHoaLoaiBuuKien(const string& loai) {
    string loaiInHoa = loai;
    transform(loaiInHoa.begin(), loaiInHoa.end(), loaiInHoa.begin(),
        [](unsigned char kyTu) {
            return static_cast<char>(toupper(kyTu));
        });

    if (loaiInHoa == "BINH_THUONG"
        || loaiInHoa == "HOA_TOC"
        || loaiInHoa == "NHANH") {
        return loaiInHoa;
    }

    return "";
}

string chuanHoaTrangThaiBuuKien(const string& trangThai) {
    string trangThaiInHoa = trangThai;
    transform(trangThaiInHoa.begin(), trangThaiInHoa.end(),
        trangThaiInHoa.begin(), [](unsigned char kyTu) {
            return static_cast<char>(toupper(kyTu));
        });

    if (trangThaiInHoa == "CHO_XU_LY"
        || trangThaiInHoa == "DA_TIEP_NHAN"
        || trangThaiInHoa == "DANG_VAN_CHUYEN"
        || trangThaiInHoa == "DA_GIAO"
        || trangThaiInHoa == "GIAO_THAT_BAI"
        || trangThaiInHoa == "DA_HUY") {
        return trangThaiInHoa;
    }

    return "";
}

unique_ptr<BUUKIEN> taoBuuKien(string loai) {
    const string loaiInHoa = chuanHoaLoaiBuuKien(loai);
    unique_ptr<BUUKIEN> buuKien;
    if (loaiInHoa == "BINH_THUONG") {
        buuKien = make_unique<BUUKIENBINHTHUONG>();
    } else if (loaiInHoa == "HOA_TOC") {
        buuKien = make_unique<BUUKIENHOATOC>();
    } else if (loaiInHoa == "NHANH") {
        buuKien = make_unique<BUUKIENNHANH>();
    }

    if (buuKien) {
        buuKien->SetLoaiBuuKien(loaiInHoa);
    }
    return buuKien;
}

void ganThongTin(BUUKIEN& buuKien, const ThongTinBuuKien& thongTin) {
    buuKien.SetMaBuuKien(thongTin.maBuuKien);
    buuKien.SetTrongLuong(thongTin.trongLuong);
    buuKien.SetDiaChiGui(thongTin.diaChiGui);
    buuKien.SetDiaChiNhan(thongTin.diaChiNhan);
    buuKien.SetNgayGui(thongTin.ngayGui);
    buuKien.SetTrangThai(chuanHoaTrangThaiBuuKien(thongTin.trangThai));
    buuKien.SetMaNguoiGui(thongTin.maNguoiGui);
    buuKien.SetMaNguoiNhan(thongTin.maNguoiNhan);
    buuKien.SetMaNhanVienTiepNhan(thongTin.maNhanVienTiepNhan);
    buuKien.SetMaChuyen(thongTin.maChuyen);
    buuKien.SetPhiDichVu(thongTin.phiDichVu);
    buuKien.SetThoiGianGiaoDuKien(thongTin.thoiGianGiaoDuKien);
    buuKien.SetTongPhi(thongTin.tongPhi);
}

string taoMaBuuKienMoi(const string& ngay, size_t soThuTu) {
    const string tienTo = "BK" + ngay;
    ostringstream maBuuKien;
    maBuuKien << tienTo << setw(4) << setfill('0') << soThuTu;
    return maBuuKien.str();
}

ThongTinBuuKien chuyenSangThongTin(const BUUKIEN& buuKien) {
    ThongTinBuuKien thongTin;
    thongTin.maBuuKien = buuKien.GetMaBuuKien();
    thongTin.loaiBuuKien = buuKien.GetLoaiBuuKien();
    thongTin.trongLuong = buuKien.GetTrongLuong();
    thongTin.diaChiGui = buuKien.GetDiaChiGui();
    thongTin.diaChiNhan = buuKien.GetDiaChiNhan();
    thongTin.ngayGui = buuKien.GetNgayGui();
    thongTin.trangThai = buuKien.GetTrangThai();
    thongTin.maNguoiGui = buuKien.GetMaNguoiGui();
    thongTin.maNguoiNhan = buuKien.GetMaNguoiNhan();
    thongTin.maNhanVienTiepNhan = buuKien.GetMaNhanVienTiepNhan();
    thongTin.maChuyen = buuKien.GetMaChuyen();
    thongTin.phiDichVu = buuKien.GetPhiDichVu();
    thongTin.thoiGianGiaoDuKien = buuKien.GetThoiGianGiaoDuKien();
    thongTin.tongPhi = buuKien.GetTongPhi();
    return thongTin;
}
}

BUUKIENSERVICE::BUUKIENSERVICE(IBUUKIENREPOSITORY& repository)
    : repository(repository),
      so_luong_buu_kien_hom_nay(0),
      ngay_cua_bo_dem(layNgayHienTai()) {}

KetQuaThemBuuKien BUUKIENSERVICE::themBuuKien(
    ThongTinBuuKien& thongTin) {
    unique_ptr<BUUKIEN> buuKien = taoBuuKien(thongTin.loaiBuuKien);
    if (!buuKien) {
        return KetQuaThemBuuKien::LOAI_KHONG_HOP_LE;
    }
    if (chuanHoaTrangThaiBuuKien(thongTin.trangThai).empty()) {
        return KetQuaThemBuuKien::TRANG_THAI_KHONG_HOP_LE;
    }

    const string ngayHienTai = layNgayHienTai();

    size_t soThuTu =
        static_cast<size_t>(so_luong_buu_kien_hom_nay) + 1;
    string maMoi = taoMaBuuKienMoi(ngayHienTai, soThuTu);
    if (maMoi.empty()) {
        return KetQuaThemBuuKien::MA_TRONG;
    }
    while (repository.contains(maMoi)) {
        maMoi = taoMaBuuKienMoi(ngayHienTai, ++soThuTu);
    }
    ganThongTin(*buuKien, thongTin);
    buuKien->SetMaBuuKien(maMoi);

    if (!repository.add(move(buuKien))) {
        return KetQuaThemBuuKien::LOI_LUU_TRU;
    }

    thongTin.maBuuKien = maMoi;
    so_luong_buu_kien_hom_nay = static_cast<int>(soThuTu);
    return KetQuaThemBuuKien::THANH_CONG;
}

bool BUUKIENSERVICE::timBuuKienTheoMa(
    const string& maBuuKien,
    ThongTinBuuKien& ketQua) const {
    if (maBuuKien.empty()) {
        return false;
    }

    const BUUKIEN* buuKien = repository.findByMaBuuKien(maBuuKien);
    if (buuKien == nullptr) {
        return false;
    }

    ketQua = chuyenSangThongTin(*buuKien);
    return true;
}

KetQuaCapNhatBuuKien BUUKIENSERVICE::capNhatBuuKien(
    const string& maBuuKien,
    const ThongTinBuuKien& thongTin) {
    if (repository.findByMaBuuKien(maBuuKien) == nullptr) {
        return KetQuaCapNhatBuuKien::KHONG_TIM_THAY;
    }

    unique_ptr<BUUKIEN> buuKien = taoBuuKien(thongTin.loaiBuuKien);
    if (!buuKien) {
        return KetQuaCapNhatBuuKien::LOAI_KHONG_HOP_LE;
    }
    if (chuanHoaTrangThaiBuuKien(thongTin.trangThai).empty()) {
        return KetQuaCapNhatBuuKien::TRANG_THAI_KHONG_HOP_LE;
    }

    ThongTinBuuKien thongTinCapNhat = thongTin;
    thongTinCapNhat.maBuuKien = maBuuKien;
    ganThongTin(*buuKien, thongTinCapNhat);

    return repository.update(maBuuKien, move(buuKien))
        ? KetQuaCapNhatBuuKien::THANH_CONG
        : KetQuaCapNhatBuuKien::LOI_LUU_TRU;
}

KetQuaXuLyBuuKien BUUKIENSERVICE::huyBuuKien(
    const string& maBuuKien) {
    const BUUKIEN* buuKien = repository.findByMaBuuKien(maBuuKien);
    if (buuKien == nullptr) {
        return KetQuaXuLyBuuKien::KHONG_TIM_THAY;
    }
    if (chuanHoaTrangThaiBuuKien(buuKien->GetTrangThai()) == "DA_HUY") {
        return KetQuaXuLyBuuKien::DA_HUY;
    }

    return repository.updateTrangThai(maBuuKien, "DA_HUY")
        ? KetQuaXuLyBuuKien::THANH_CONG
        : KetQuaXuLyBuuKien::LOI_LUU_TRU;
}

KetQuaXuLyBuuKien BUUKIENSERVICE::xoaBuuKien(
    const string& maBuuKien) {
    if (repository.findByMaBuuKien(maBuuKien) == nullptr) {
        return KetQuaXuLyBuuKien::KHONG_TIM_THAY;
    }

    return repository.remove(maBuuKien)
        ? KetQuaXuLyBuuKien::THANH_CONG
        : KetQuaXuLyBuuKien::LOI_LUU_TRU;
}

vector<ThongTinBuuKien> BUUKIENSERVICE::layDanhSachBuuKien() const {
    const vector<const BUUKIEN*> buuKienTrongKho = repository.getAll();
    vector<ThongTinBuuKien> danhSach;
    danhSach.reserve(buuKienTrongKho.size());

    for (const BUUKIEN* buuKien : buuKienTrongKho) {
        danhSach.push_back(chuyenSangThongTin(*buuKien));
    }

    return danhSach;
}


string BUUKIENSERVICE::layNgayHienTai() {
    time_t now = time(nullptr);

    tm* current = localtime(&now);

    if (current == nullptr) {
        throw runtime_error("Khong lay duoc ngay he thong");
    }

    stringstream ss;

    ss << setw(2) << setfill('0') << current->tm_mday
       << setw(2) << setfill('0') << (current->tm_mon + 1)
       << (current->tm_year + 1900);

    return ss.str();
}

int BUUKIENSERVICE::GetSoLuongBuuKienHomNay(){
    return so_luong_buu_kien_hom_nay;
}

void BUUKIENSERVICE::SetSoLuongBuuKienHomNay(const int& slm){
    so_luong_buu_kien_hom_nay=slm;
}

