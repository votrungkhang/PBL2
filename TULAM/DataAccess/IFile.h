#ifndef IFILE_H
#define IFILE_H

#include "../Business/IBuuKienRepository.h"

class IFILE {
protected:
    std::string nameFile;

public:
    explicit IFILE(const std::string& nameFile);
    virtual ~IFILE() = default;
    virtual bool save(IBUUKIENREPOSITORY&) = 0;
    virtual bool read(IBUUKIENREPOSITORY&) = 0;
};

inline IFILE::IFILE(const std::string& nameFile)
    : nameFile(nameFile) {}

#endif
