#ifndef IFILENHANVIEN_H
#define IFILENHANVIEN_H

#include "../Business/INhanVienRepository.h"

class IFILENHANVIEN {
protected:
    std::string nameFile;

public:
    explicit IFILENHANVIEN(const std::string& nameFile)
        : nameFile(nameFile) {}
    virtual ~IFILENHANVIEN() = default;
    virtual bool save(INHANVIENREPOSITORY&) = 0;
    virtual bool read(INHANVIENREPOSITORY&) = 0;
};

#endif
