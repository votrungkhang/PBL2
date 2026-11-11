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

unique_ptr<BuuKien> taoBuuKien(string loai) {
    const string loaiInHoa = chuanHoaLoaiBuuKien(loai);
    unique_ptr<BuuKien> buuKien;
    if (loaiInHoa == "BINH_THUONG") {
        buuKien = make_unique<BuuKienBinhThuong>();
    } else if (loaiInHoa == "HOA_TOC") {
        buuKien = make_unique<BuuKienHoaToc>();
    } else if (loaiInHoa == "NHANH") {
        buuKien = make_unique<BuuKienNhanh>();
    }

    if (buuKien) {
        buuKien->SetLoaiBuuKien(loaiInHoa);
    }
    return buuKien;
}

void ganThongTin(BuuKien& buuKien, const ThongTinBuuKien& thongTin) {
    buuKien.SetMaBuuKien(thongTin.maBuuKien);
    buuKien.SetTrongLuong(thongTin.trongLuong);
    buuKien.SetDiaChiGui(thongTin.diaChiGui);
    buuKien.SetDiaChiNhan(thongTin.diaChiNhan);
    buuKien.SetNgayGui(thongTin.ngayGui);
    buuKien.SetTrangThai(thongTin.trangThai);
    buuKien.SetMaNguoiGui(thongTin.maNguoiGui);
    buuKien.SetMaNguoiNhan(thongTin.maNguoiNhan);
    buuKien.SetMaNhanVienTiepNhan(thongTin.maNhanVienTiepNhan);
    buuKien.SetMaChuyen(thongTin.maChuyen);
    buuKien.SetPhiDichVu(thongTin.phiDichVu);
    buuKien.SetThoiGianGiaoDuKien(thongTin.thoiGianGiaoDuKien);
    buuKien.SetTongPhi(thongTin.tongPhi);
}

string taoMaBuuKienMoi(size_t soThuTu) {
    const string tienTo = "BK" + BuuKienService::layNgayHienTai();
    ostringstream maBuuKien;
    maBuuKien << tienTo << setw(4) << setfill('0') << soThuTu;
    return maBuuKien.str();
}

ThongTinBuuKien chuyenSangThongTin(const BuuKien& buuKien) {
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

BuuKienService::BuuKienService(IBuuKienRepository& repository)
    : repository(repository),so_luong_buu_kien_hom_nay(0) {}

KetQuaThemBuuKien BuuKienService::themBuuKien(
    ThongTinBuuKien& thongTin) {
    unique_ptr<BuuKien> buuKien = taoBuuKien(thongTin.loaiBuuKien);
    if (!buuKien) {
        return KetQuaThemBuuKien::LOAI_KHONG_HOP_LE;
    }

    size_t soThuTu = static_cast<size_t>(so_luong_buu_kien_hom_nay) + 1;
    string maMoi = taoMaBuuKienMoi(soThuTu);
    // while (repository.contains(maMoi)) {
    //     maMoi = taoMaBuuKienMoi(++soThuTu);
    // }
    ganThongTin(*buuKien, thongTin);
    buuKien->SetMaBuuKien(maMoi);

    if (!repository.add(move(buuKien))) {
        return KetQuaThemBuuKien::LOI_LUU_TRU;
    }

    thongTin.maBuuKien = maMoi;
    so_luong_buu_kien_hom_nay+=1;
    return KetQuaThemBuuKien::THANH_CONG;
}

bool BuuKienService::timBuuKienTheoMa(
    const string& maBuuKien,
    ThongTinBuuKien& ketQua) const {
    if (maBuuKien.empty()) {
        return false;
    }

    const BuuKien* buuKien = repository.findByMaBuuKien(maBuuKien);
    if (buuKien == nullptr) {
        return false;
    }

    ketQua = chuyenSangThongTin(*buuKien);
    return true;
}

KetQuaCapNhatBuuKien BuuKienService::capNhatBuuKien(
    const string& maBuuKien,
    const ThongTinBuuKien& thongTin) {
    if (repository.findByMaBuuKien(maBuuKien) == nullptr) {
        return KetQuaCapNhatBuuKien::KHONG_TIM_THAY;
    }

    unique_ptr<BuuKien> buuKien = taoBuuKien(thongTin.loaiBuuKien);
    if (!buuKien) {
        return KetQuaCapNhatBuuKien::LOAI_KHONG_HOP_LE;
    }

    ThongTinBuuKien thongTinCapNhat = thongTin;
    thongTinCapNhat.maBuuKien = maBuuKien;
    ganThongTin(*buuKien, thongTinCapNhat);

    return repository.update(maBuuKien, move(buuKien))
        ? KetQuaCapNhatBuuKien::THANH_CONG
        : KetQuaCapNhatBuuKien::LOI_LUU_TRU;
}

KetQuaXuLyBuuKien BuuKienService::huyBuuKien(
    const string& maBuuKien) {
    const BuuKien* buuKien = repository.findByMaBuuKien(maBuuKien);
    if (buuKien == nullptr) {
        return KetQuaXuLyBuuKien::KHONG_TIM_THAY;
    }
    if (buuKien->GetTrangThai() == "DA_HUY") {
        return KetQuaXuLyBuuKien::DA_HUY;
    }

    return repository.updateTrangThai(maBuuKien, "DA_HUY")
        ? KetQuaXuLyBuuKien::THANH_CONG
        : KetQuaXuLyBuuKien::LOI_LUU_TRU;
}

KetQuaXuLyBuuKien BuuKienService::xoaBuuKien(
    const string& maBuuKien) {
    if (repository.findByMaBuuKien(maBuuKien) == nullptr) {
        return KetQuaXuLyBuuKien::KHONG_TIM_THAY;
    }

    return repository.remove(maBuuKien)
        ? KetQuaXuLyBuuKien::THANH_CONG
        : KetQuaXuLyBuuKien::LOI_LUU_TRU;
}

vector<ThongTinBuuKien> BuuKienService::layDanhSachBuuKien() const {
    const vector<const BuuKien*> buuKienTrongKho = repository.getAll();
    vector<ThongTinBuuKien> danhSach;
    danhSach.reserve(buuKienTrongKho.size());

    for (const BuuKien* buuKien : buuKienTrongKho) {
        danhSach.push_back(chuyenSangThongTin(*buuKien));
    }

    return danhSach;
}


string BuuKienService::layNgayHienTai() {
    time_t now = time(nullptr);

    tm* current = localtime(&now);

    if (current == nullptr) {
        throw runtime_error("Khong lay duoc ngay he thong");
    }

    stringstream ss;

    ss << (current->tm_year + 1900)
       << setw(2) << setfill('0') << (current->tm_mon + 1)
       << setw(2) << setfill('0') << current->tm_mday;

    return ss.str();
}

int BuuKienService::GetSoLuongBuuKienHomNay(){
    return so_luong_buu_kien_hom_nay;
}

void BuuKienService::SetSoLuongBuuKienHomNay(const int& slm){
    so_luong_buu_kien_hom_nay=slm;
}

