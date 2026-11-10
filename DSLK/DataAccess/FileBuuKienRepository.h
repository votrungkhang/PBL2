#ifndef FILEBUUKIENREPOSITORY_H
#define FILEBUUKIENREPOSITORY_H

#include <string>
#include "IBuuKienRepository.h"
#include "LinkedListBuuKienRepository.h"

class FileBuuKienRepository : public IBuuKienRepository {
private:
    std::string filePath;
    LinkedListBuuKienRepository storage;

    void load();

public:
    explicit FileBuuKienRepository(
        const std::string& filePath = "buu_kien.txt");

    bool add(std::unique_ptr<BuuKien> buuKien) override;
    bool contains(const std::string& maBuuKien) const override;
    std::vector<const BuuKien*> getAll() const override;
    void save() const;
};

#endif
