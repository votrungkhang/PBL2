#ifndef IFILEBUUKIEN_H
#define IFILEBUUKIEN_H

#include "../Business/IBuuKienRepository.h"

class IFileBuuKien {
protected:
    std::string nameFile;

public:
    explicit IFileBuuKien(const std::string& nameFile);
    virtual ~IFileBuuKien() = default;
    virtual bool save(IBuuKienRepository&) = 0;
    virtual bool read(IBuuKienRepository&) = 0;
};

inline IFileBuuKien::IFileBuuKien(const std::string& nameFile)
    : nameFile(nameFile) {}

#endif
