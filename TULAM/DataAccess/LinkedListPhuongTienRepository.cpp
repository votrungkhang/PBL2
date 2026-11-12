#include "LinkedListPhuongTienRepository.h"

#include <utility>

LINKEDLISTPHUONGTIENREPOSITORY::Node::Node(
    std::unique_ptr<PHUONGTIEN> phuongTien)
    : data(std::move(phuongTien)), next(nullptr) {}

LINKEDLISTPHUONGTIENREPOSITORY::LINKEDLISTPHUONGTIENREPOSITORY()
    : head(nullptr), tail(nullptr), soLuongPhuongTien(0) {}

LINKEDLISTPHUONGTIENREPOSITORY::~LINKEDLISTPHUONGTIENREPOSITORY() {
    while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

bool LINKEDLISTPHUONGTIENREPOSITORY::add(
    std::unique_ptr<PHUONGTIEN> phuongTien) {
    if (!phuongTien) {
        return false;
    }

    Node* newNode = new Node(std::move(phuongTien));
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    ++soLuongPhuongTien;
    return true;
}

bool LINKEDLISTPHUONGTIENREPOSITORY::contains(
    const std::string& maPhuongTien) const {
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaPhuongTien() == maPhuongTien) {
            return true;
        }
    }
    return false;
}

const PHUONGTIEN* LINKEDLISTPHUONGTIENREPOSITORY::findByMaPhuongTien(
    const std::string& maPhuongTien) const {
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaPhuongTien() == maPhuongTien) {
            return current->data.get();
        }
    }
    return nullptr;
}

bool LINKEDLISTPHUONGTIENREPOSITORY::update(
    const std::string& maPhuongTien,
    std::unique_ptr<PHUONGTIEN> phuongTien) {
    if (!phuongTien
        || phuongTien->GetMaPhuongTien() != maPhuongTien) {
        return false;
    }

    for (Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaPhuongTien() == maPhuongTien) {
            current->data = std::move(phuongTien);
            return true;
        }
    }
    return false;
}

bool LINKEDLISTPHUONGTIENREPOSITORY::remove(
    const std::string& maPhuongTien) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->data->GetMaPhuongTien() == maPhuongTien) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (tail == current) {
                tail = previous;
            }

            delete current;
            --soLuongPhuongTien;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

std::vector<const PHUONGTIEN*>
LINKEDLISTPHUONGTIENREPOSITORY::getAll() const {
    std::vector<const PHUONGTIEN*> result;
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        result.push_back(current->data.get());
    }
    return result;
}

int LINKEDLISTPHUONGTIENREPOSITORY::getSoLuongPhuongTien() const {
    return soLuongPhuongTien;
}

void LINKEDLISTPHUONGTIENREPOSITORY::setSoLuongPhuongTien(
    const int& soLuongPhuongTienMoi) {
    soLuongPhuongTien = soLuongPhuongTienMoi;
}
