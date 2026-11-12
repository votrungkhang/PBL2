#ifndef LINKEDLISTPHUONGTIENREPOSITORY_H
#define LINKEDLISTPHUONGTIENREPOSITORY_H

#include "../Business/IPhuongTienRepository.h"

class LINKEDLISTPHUONGTIENREPOSITORY : public IPHUONGTIENREPOSITORY {
private:
    struct Node {
        std::unique_ptr<PHUONGTIEN> data;
        Node* next;
        explicit Node(std::unique_ptr<PHUONGTIEN> phuongTien);
    };

    Node* head;
    Node* tail;
    int soLuongPhuongTien;

public:
    LINKEDLISTPHUONGTIENREPOSITORY();
    ~LINKEDLISTPHUONGTIENREPOSITORY() override;
    LINKEDLISTPHUONGTIENREPOSITORY(
        const LINKEDLISTPHUONGTIENREPOSITORY&) = delete;
    LINKEDLISTPHUONGTIENREPOSITORY& operator=(
        const LINKEDLISTPHUONGTIENREPOSITORY&) = delete;

    bool add(std::unique_ptr<PHUONGTIEN> phuongTien) override;
    bool contains(const std::string& maPhuongTien) const override;
    const PHUONGTIEN* findByMaPhuongTien(
        const std::string& maPhuongTien) const override;
    bool update(
        const std::string& maPhuongTien,
        std::unique_ptr<PHUONGTIEN> phuongTien) override;
    bool remove(const std::string& maPhuongTien) override;
    std::vector<const PHUONGTIEN*> getAll() const override;
    int getSoLuongPhuongTien() const override;
    void setSoLuongPhuongTien(
        const int& soLuongPhuongTienMoi) override;
};

#endif
