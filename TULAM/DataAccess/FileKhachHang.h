#ifndef FILEKHACHHANG_H
#define FILEKHACHHANG_H

#include "IFileKhachHang.h"

class FILEKHACHHANG : public IFILEKHACHHANG {
public:
    explicit FILEKHACHHANG(const std::string& nameFile);
    bool save(IKHACHHANGREPOSITORY&) override;
    bool read(IKHACHHANGREPOSITORY&) override;
};

#endif