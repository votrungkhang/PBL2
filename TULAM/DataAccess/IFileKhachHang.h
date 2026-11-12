#ifndef IFILEKHACHHANG_H
#define IFILEKHACHHANG_H

#include "../Business/IKhachHangRepository.h"

class IFILEKHACHHANG {
protected:
    std::string nameFile;

public:
    explicit IFILEKHACHHANG(const std::string& nameFile)
        : nameFile(nameFile) {}
    virtual ~IFILEKHACHHANG() = default;
    virtual bool save(IKHACHHANGREPOSITORY&) = 0;
    virtual bool read(IKHACHHANGREPOSITORY&) = 0;
};

#endif
