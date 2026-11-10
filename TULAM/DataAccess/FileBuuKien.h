#ifndef FILEBUUKIEN_H
#define FILEBUUKIEN_H

#include "IFileBuuKien.h"

class FileBuuKien : public IFileBuuKien {
public:
    explicit FileBuuKien(const std::string&);
    bool save(IBuuKienRepository&) override;
    bool read(IBuuKienRepository&) override;
};

#endif
