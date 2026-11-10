#ifndef LINKEDLISTBUUKIENREPOSITORY_H
#define LINKEDLISTBUUKIENREPOSITORY_H

#include "IBuuKienRepository.h"

class LinkedListBuuKienRepository : public IBuuKienRepository {
private:
    struct Node {
        std::unique_ptr<BuuKien> data;
        Node* next;

        explicit Node(std::unique_ptr<BuuKien> buuKien);
    };

    Node* head;
    Node* tail;

public:
    LinkedListBuuKienRepository();
    ~LinkedListBuuKienRepository() override;

    bool add(std::unique_ptr<BuuKien> buuKien) override;
    bool contains(const std::string& maBuuKien) const override;
    std::vector<const BuuKien*> getAll() const override;

    LinkedListBuuKienRepository(const LinkedListBuuKienRepository&) = delete;
    LinkedListBuuKienRepository& operator=(const LinkedListBuuKienRepository&) = delete;
};

#endif
