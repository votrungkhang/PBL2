#ifndef IBUUKIENREPOSITORY_H
#define IBUUKIENREPOSITORY_H

#include <memory>
#include <string>
#include <vector>
#include "../Domain/BuuKien.h"

class IBUUKIENREPOSITORY {
public:
    virtual ~IBUUKIENREPOSITORY() = default;
    virtual bool add(std::unique_ptr<BUUKIEN>) = 0;
    virtual bool contains(const std::string& maBuuKien) const = 0;
    virtual const BUUKIEN* findByMaBuuKien(
        const std::string& maBuuKien) const = 0;
    virtual bool update(
        const std::string& maBuuKien,
        std::unique_ptr<BUUKIEN> buuKien) = 0;
    virtual bool updateTrangThai(
        const std::string& maBuuKien,
        const std::string& trangThai) = 0;
    virtual bool remove(const std::string& maBuuKien) = 0;
    virtual std::vector<const BUUKIEN*> getAll() const = 0;
    virtual int getSoLuongBuuKien() const = 0;
    virtual void setSoLuongBuuKien(const int&) =0;
};

#endif
