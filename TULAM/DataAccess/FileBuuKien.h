#ifndef FILEBUUKIEN_H
#define FILEBUUKIEN_H

#include "IFile.h"

class FILEBUUKIEN : public IFILE{
public:
    explicit FILEBUUKIEN(const std::string&);
    bool save(IBUUKIENREPOSITORY&) override;
    bool read(IBUUKIENREPOSITORY&) override;
};

#endif
