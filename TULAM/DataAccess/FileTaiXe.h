#ifndef FILETAIXE_H
#define FILETAIXE_H

#include "IFileTaiXe.h"

class FILETAIXE : public IFILETAIXE {
public:
    explicit FILETAIXE(const std::string& nameFile);
    bool save(ITAIXEREPOSITORY&) override;
    bool read(ITAIXEREPOSITORY&) override;
};

#endif
