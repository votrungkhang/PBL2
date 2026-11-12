#ifndef LINKEDLISTKHACHHANGREPOSITORY_H
#define LINKEDLISTKHACHHANGREPOSITORY_H

#include "../Business/IKhachHangRepository.h"

class LINKEDLISTKHACHHANGREPOSITORY : public IKHACHHANGREPOSITORY {
private:
    struct Node {
        std::unique_ptr<KHACHHANG> data;
        Node* next;
        explicit Node(std::unique_ptr<KHACHHANG> khachHang);
    };

    Node* head;
    Node* tail;
    int soLuongKhachHang;

public:
    LINKEDLISTKHACHHANGREPOSITORY();
    ~LINKEDLISTKHACHHANGREPOSITORY() override;
    LINKEDLISTKHACHHANGREPOSITORY(
        const LINKEDLISTKHACHHANGREPOSITORY&) = delete;
    LINKEDLISTKHACHHANGREPOSITORY& operator=(
        const LINKEDLISTKHACHHANGREPOSITORY&) = delete;

    bool add(std::unique_ptr<KHACHHANG> khachHang) override;
    bool contains(const std::string& maKhachHang) const override;
    const KHACHHANG* findByMaKhachHang(
        const std::string& maKhachHang) const override;
    bool update(
        const std::string& maKhachHang,
        std::unique_ptr<KHACHHANG> khachHang) override;
    bool remove(const std::string& maKhachHang) override;
    std::vector<const KHACHHANG*> getAll() const override;
    int getSoLuongKhachHang() const override;
    void setSoLuongKhachHang(const int& soLuongKhachHangMoi) override;
};

#endif