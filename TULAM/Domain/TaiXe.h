#ifndef TAIXE_H
#define TAIXE_H

#include <string>

class TAIXE {
private:
    std::string ma_tai_xe;
    std::string ho_ten;
    std::string sdt;
    std::string bang_lai;

public:
    TAIXE(
        const std::string& ma_tai_xe = "",
        const std::string& ho_ten = "",
        const std::string& sdt = "",
        const std::string& bang_lai = "");

    const std::string& GetMaTaiXe() const;
    void SetMaTaiXe(const std::string& maTaiXeMoi);

    const std::string& GetHoTen() const;
    void SetHoTen(const std::string& hoTenMoi);

    const std::string& GetSdt() const;
    void SetSdt(const std::string& sdtMoi);

    const std::string& GetBangLai() const;
    void SetBangLai(const std::string& bangLaiMoi);
};

#endif
