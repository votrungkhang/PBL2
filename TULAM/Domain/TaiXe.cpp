#include "TaiXe.h"

TAIXE::TAIXE(
    const std::string& ma_tai_xe,
    const std::string& ho_ten,
    const std::string& sdt,
    const std::string& bang_lai)
    : ma_tai_xe(ma_tai_xe),
      ho_ten(ho_ten),
      sdt(sdt),
      bang_lai(bang_lai) {}

const std::string& TAIXE::GetMaTaiXe() const {
    return ma_tai_xe;
}

void TAIXE::SetMaTaiXe(const std::string& maTaiXeMoi) {
    ma_tai_xe = maTaiXeMoi;
}

const std::string& TAIXE::GetHoTen() const {
    return ho_ten;
}

void TAIXE::SetHoTen(const std::string& hoTenMoi) {
    ho_ten = hoTenMoi;
}

const std::string& TAIXE::GetSdt() const {
    return sdt;
}

void TAIXE::SetSdt(const std::string& sdtMoi) {
    sdt = sdtMoi;
}

const std::string& TAIXE::GetBangLai() const {
    return bang_lai;
}

void TAIXE::SetBangLai(const std::string& bangLaiMoi) {
    bang_lai = bangLaiMoi;
}
