#ifndef IFILEPHUONGTIEN_H
#define IFILEPHUONGTIEN_H

#include "../Business/IPhuongTienRepository.h"

class IFILEPHUONGTIEN {
protected:
    std::string nameFile;

public:
    explicit IFILEPHUONGTIEN(const std::string& nameFile)
        : nameFile(nameFile) {}
    virtual ~IFILEPHUONGTIEN() = default;
    virtual bool save(IPHUONGTIENREPOSITORY&) = 0;
    virtual bool read(IPHUONGTIENREPOSITORY&) = 0;
};

#endif
