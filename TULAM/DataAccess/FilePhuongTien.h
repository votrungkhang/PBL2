#ifndef FILEPHUONGTIEN_H
#define FILEPHUONGTIEN_H

#include "IFilePhuongTien.h"

class FILEPHUONGTIEN : public IFILEPHUONGTIEN {
public:
    explicit FILEPHUONGTIEN(const std::string& nameFile);
    bool save(IPHUONGTIENREPOSITORY&) override;
    bool read(IPHUONGTIENREPOSITORY&) override;
};

#endif
