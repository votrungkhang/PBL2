#ifndef BUUKIENBINHTHUONG_H
#define BUUKIENBINHTHUONG_H

#include <string>
#include "BuuKien.h"

class BuuKienBinhThuong : public BuuKien {
private:
    std::string thoiGianGiaoDuKien;

public:
    explicit BuuKienBinhThuong(
        const std::string& maBuuKien,
        const std::string& thoiGianGiaoDuKien = "");

    std::string getLoai() const override;
    const std::string& getThoiGianGiaoDuKien() const override;
};

#endif
