#ifndef FILENHANVIEN_H
#define FILENHANVIEN_H

#include "IFileNhanVien.h"

class FILENHANVIEN : public IFILENHANVIEN {
public:
    explicit FILENHANVIEN(const std::string& nameFile);
    bool save(INHANVIENREPOSITORY&) override;
    bool read(INHANVIENREPOSITORY&) override;
};

#endif
