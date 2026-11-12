#ifndef ITAIXEREPOSITORY_H
#define ITAIXEREPOSITORY_H

#include <memory>
#include <string>
#include <vector>
#include "../Domain/TaiXe.h"

class ITAIXEREPOSITORY {
public:
    virtual ~ITAIXEREPOSITORY() = default;
    virtual bool add(std::unique_ptr<TAIXE> taiXe) = 0;
    virtual bool contains(const std::string& maTaiXe) const = 0;
    virtual const TAIXE* findByMaTaiXe(
        const std::string& maTaiXe) const = 0;
    virtual bool update(
        const std::string& maTaiXe,
        std::unique_ptr<TAIXE> taiXe) = 0;
    virtual bool remove(const std::string& maTaiXe) = 0;
    virtual std::vector<const TAIXE*> getAll() const = 0;
    virtual int getSoLuongTaiXe() const = 0;
    virtual void setSoLuongTaiXe(const int& soLuongTaiXeMoi) = 0;
};

#endif
