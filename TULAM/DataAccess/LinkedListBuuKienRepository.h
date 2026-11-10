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
    bool add(unique_ptr<BuuKien>) override;
    bool contains(const string& ) const override;
    vector<const BuuKien*> getAll() const override;

    int getSoLuongBuuKien();
    void setSoLuongBuuKien(const int&);
};

#endif
