#ifndef LINKEDLISTBUUKIENREPOSITORY_H
#define LINKEDLISTBUUKIENREPOSITORY_H

#include "../Business/IBuuKienRepository.h"

class LINKEDLISTBUUKIENREPOSITORY : public IBUUKIENREPOSITORY {
private:
    struct Node {
        unique_ptr<BUUKIEN> data;
        Node* next;
        Node(unique_ptr<BUUKIEN>);
    };

    Node* head;
    Node* tail;
    int soLuongBuuKien;
public:
    LINKEDLISTBUUKIENREPOSITORY();
    ~LINKEDLISTBUUKIENREPOSITORY();
    LINKEDLISTBUUKIENREPOSITORY(const LINKEDLISTBUUKIENREPOSITORY&) = delete;
    LINKEDLISTBUUKIENREPOSITORY& operator=(
        const LINKEDLISTBUUKIENREPOSITORY&) = delete;

    bool add(unique_ptr<BUUKIEN>) override;
    bool contains(const string& ) const override;
    const BUUKIEN* findByMaBuuKien(
        const string& maBuuKien) const override;
    bool update(
        const string& maBuuKien,
        unique_ptr<BUUKIEN> buuKien) override;
    bool updateTrangThai(
        const string& maBuuKien,
        const string& trangThai) override;
    bool remove(const string& maBuuKien) override;
    vector<const BUUKIEN*> getAll() const override;

    int getSoLuongBuuKien() const override;
    void setSoLuongBuuKien(const int&) override;
};

#endif
