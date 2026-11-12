#ifndef IFILETAIXE_H
#define IFILETAIXE_H

#include "../Business/ITaiXeRepository.h"

class IFILETAIXE {
protected:
    std::string nameFile;

public:
    explicit IFILETAIXE(const std::string& nameFile)
        : nameFile(nameFile) {}
    virtual ~IFILETAIXE() = default;
    virtual bool save(ITAIXEREPOSITORY&) = 0;
    virtual bool read(ITAIXEREPOSITORY&) = 0;
};

#endif
