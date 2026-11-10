#ifndef BUUKIEN_H
#define BUUKIEN_H

#include <string>

class BuuKien {
protected:
    std::string maBuuKien;

public:
    explicit BuuKien(const std::string& maBuuKien);
    virtual ~BuuKien() = default;

    const std::string& getMaBuuKien() const;
    void setMaBuuKien(const std::string& maMoi);
    virtual std::string getLoai() const = 0;
    virtual const std::string& getThoiGianGiaoDuKien() const = 0;
};

#endif
