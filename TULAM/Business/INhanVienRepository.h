#ifndef INHANVIENREPOSITORY_H
#define INHANVIENREPOSITORY_H

#include <memory>
#include <string>
#include <vector>
#include "../Domain/NhanVien.h"

class INHANVIENREPOSITORY {
public:
    virtual ~INHANVIENREPOSITORY() = default;
    virtual bool add(std::unique_ptr<NHANVIEN> nhanVien) = 0;
    virtual bool contains(const std::string& maNhanVien) const = 0;
    virtual const NHANVIEN* findByMaNhanVien(
        const std::string& maNhanVien) const = 0;
    virtual bool update(
        const std::string& maNhanVien,
        std::unique_ptr<NHANVIEN> nhanVien) = 0;
    virtual bool remove(const std::string& maNhanVien) = 0;
    virtual std::vector<const NHANVIEN*> getAll() const = 0;
    virtual int getSoLuongNhanVien() const = 0;
    virtual void setSoLuongNhanVien(
        const int& soLuongNhanVienMoi) = 0;
};

#endif
