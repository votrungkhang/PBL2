#ifndef LINKEDLISTBUUKIENREPOSITORY_H
#define LINKEDLISTBUUKIENREPOSITORY_H

#include "../Business/IBuuKienRepository.h"

class LinkedListBuuKienRepository : public IBuuKienRepository {
private:
    struct Node {
        unique_ptr<BuuKien> data;
        Node* next;
        Node(unique_ptr<BuuKien>);
    };

    Node* head;
    Node* tail;
    int soLuongBuuKien;
public:
    LinkedListBuuKienRepository();
    ~LinkedListBuuKienRepository();
    LinkedListBuuKienRepository(const LinkedListBuuKienRepository&) = delete;
    LinkedListBuuKienRepository& operator=(
        const LinkedListBuuKienRepository&) = delete;

    bool add(unique_ptr<BuuKien>) override;
    bool contains(const string& ) const override;
    const BuuKien* findByMaBuuKien(
        const string& maBuuKien) const override;
    bool update(
        const string& maBuuKien,
        unique_ptr<BuuKien> buuKien) override;
    bool updateTrangThai(
        const string& maBuuKien,
        const string& trangThai) override;
    bool remove(const string& maBuuKien) override;
    vector<const BuuKien*> getAll() const override;

    int getSoLuongBuuKien();
    void setSoLuongBuuKien(const int&);
};

#endif
