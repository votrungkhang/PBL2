#ifndef LINKEDLISTTAIXEREPOSITORY_H
#define LINKEDLISTTAIXEREPOSITORY_H

#include "../Business/ITaiXeRepository.h"

class LINKEDLISTTAIXEREPOSITORY : public ITAIXEREPOSITORY {
private:
    struct Node {
        std::unique_ptr<TAIXE> data;
        Node* next;
        explicit Node(std::unique_ptr<TAIXE> taiXe);
    };

    Node* head;
    Node* tail;
    int soLuongTaiXe;

public:
    LINKEDLISTTAIXEREPOSITORY();
    ~LINKEDLISTTAIXEREPOSITORY() override;
    LINKEDLISTTAIXEREPOSITORY(
        const LINKEDLISTTAIXEREPOSITORY&) = delete;
    LINKEDLISTTAIXEREPOSITORY& operator=(
        const LINKEDLISTTAIXEREPOSITORY&) = delete;

    bool add(std::unique_ptr<TAIXE> taiXe) override;
    bool contains(const std::string& maTaiXe) const override;
    const TAIXE* findByMaTaiXe(
        const std::string& maTaiXe) const override;
    bool update(
        const std::string& maTaiXe,
        std::unique_ptr<TAIXE> taiXe) override;
    bool remove(const std::string& maTaiXe) override;
    std::vector<const TAIXE*> getAll() const override;
    int getSoLuongTaiXe() const override;
    void setSoLuongTaiXe(const int& soLuongTaiXeMoi) override;
};

#endif
