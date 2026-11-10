#ifndef BUUKIENNHANH_H
#define BUUKIENNHANH_H

#include <string>
#include "BuuKien.h"

class BuuKienNhanh : public BuuKien {
private:
    std::string thoiGianGiaoDuKien;

public:
    explicit BuuKienNhanh(
        const std::string& maBuuKien,
        const std::string& thoiGianGiaoDuKien = "");

    std::string getLoai() const override;
    const std::string& getThoiGianGiaoDuKien() const override;
};

#endif
