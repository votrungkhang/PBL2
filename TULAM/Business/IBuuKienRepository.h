#ifndef IBUUKIENREPOSITORY_H
#define IBUUKIENREPOSITORY_H

#include <memory>
#include <string>
#include <vector>
#include "../Domain/BuuKien.h"

class IBuuKienRepository {
public:
    virtual ~IBuuKienRepository() = default;
    virtual bool add(std::unique_ptr<BuuKien>) = 0;
    virtual bool contains(const std::string& maBuuKien) const = 0;
    virtual const BuuKien* findByMaBuuKien(
        const std::string& maBuuKien) const = 0;
    virtual bool update(
        const std::string& maBuuKien,
        std::unique_ptr<BuuKien> buuKien) = 0;
    virtual bool updateTrangThai(
        const std::string& maBuuKien,
        const std::string& trangThai) = 0;
    virtual bool remove(const std::string& maBuuKien) = 0;
    virtual std::vector<const BuuKien*> getAll() const = 0;
};

#endif
