#ifndef LINKEDLISTNHANVIENREPOSITORY_H
#define LINKEDLISTNHANVIENREPOSITORY_H

#include "../Business/INhanVienRepository.h"

class LINKEDLISTNHANVIENREPOSITORY : public INHANVIENREPOSITORY {
private:
    struct Node {
        std::unique_ptr<NHANVIEN> data;
        Node* next;
        explicit Node(std::unique_ptr<NHANVIEN> nhanVien);
    };

    Node* head;
    Node* tail;
    int soLuongNhanVien;

public:
    LINKEDLISTNHANVIENREPOSITORY();
    ~LINKEDLISTNHANVIENREPOSITORY() override;
    LINKEDLISTNHANVIENREPOSITORY(
        const LINKEDLISTNHANVIENREPOSITORY&) = delete;
    LINKEDLISTNHANVIENREPOSITORY& operator=(
        const LINKEDLISTNHANVIENREPOSITORY&) = delete;

    bool add(std::unique_ptr<NHANVIEN> nhanVien) override;
    bool contains(const std::string& maNhanVien) const override;
    const NHANVIEN* findByMaNhanVien(
        const std::string& maNhanVien) const override;
    bool update(
        const std::string& maNhanVien,
        std::unique_ptr<NHANVIEN> nhanVien) override;
    bool remove(const std::string& maNhanVien) override;
    std::vector<const NHANVIEN*> getAll() const override;
    int getSoLuongNhanVien() const override;
    void setSoLuongNhanVien(const int& soLuongNhanVienMoi) override;
};

#endif
