#ifndef BUUKIENHOATOC_H
#define BUUKIENHOATOC_H

#include <string>
#include "BuuKien.h"

class BuuKienHoaToc : public BuuKien {
private:
    std::string thoiGianGiaoDuKien;

public:
    explicit BuuKienHoaToc(
        const std::string& maBuuKien,
        const std::string& thoiGianGiaoDuKien = "");

    std::string getLoai() const override;
    const std::string& getThoiGianGiaoDuKien() const override;
};

#endif
