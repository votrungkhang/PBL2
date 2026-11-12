#ifndef IKHACHHANGREPOSITORY_H
#define IKHACHHANGREPOSITORY_H

#include <memory>
#include <string>
#include <vector>
#include "../Domain/KhachKhang.h"

class IKHACHHANGREPOSITORY {
public:
    virtual ~IKHACHHANGREPOSITORY() = default;
    virtual bool add(std::unique_ptr<KHACHHANG> khachHang) = 0;
    virtual bool contains(const std::string& maKhachHang) const = 0;
    virtual const KHACHHANG* findByMaKhachHang(
        const std::string& maKhachHang) const = 0;
    virtual bool update(
        const std::string& maKhachHang,
        std::unique_ptr<KHACHHANG> khachHang) = 0;
    virtual bool remove(const std::string& maKhachHang) = 0;
    virtual std::vector<const KHACHHANG*> getAll() const = 0;
    virtual int getSoLuongKhachHang() const = 0;
    virtual void setSoLuongKhachHang(
        const int& soLuongKhachHangMoi) = 0;
};

#endif
