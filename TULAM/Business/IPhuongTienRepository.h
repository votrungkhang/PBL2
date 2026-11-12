#ifndef IPHUONGTIENREPOSITORY_H
#define IPHUONGTIENREPOSITORY_H

#include <memory>
#include <string>
#include <vector>
#include "../Domain/PhuongTien.h"

class IPHUONGTIENREPOSITORY {
public:
    virtual ~IPHUONGTIENREPOSITORY() = default;
    virtual bool add(std::unique_ptr<PHUONGTIEN> phuongTien) = 0;
    virtual bool contains(const std::string& maPhuongTien) const = 0;
    virtual const PHUONGTIEN* findByMaPhuongTien(
        const std::string& maPhuongTien) const = 0;
    virtual bool update(
        const std::string& maPhuongTien,
        std::unique_ptr<PHUONGTIEN> phuongTien) = 0;
    virtual bool remove(const std::string& maPhuongTien) = 0;
    virtual std::vector<const PHUONGTIEN*> getAll() const = 0;
    virtual int getSoLuongPhuongTien() const = 0;
    virtual void setSoLuongPhuongTien(
        const int& soLuongPhuongTienMoi) = 0;
};

#endif
