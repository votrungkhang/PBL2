#include "LinkedListNhanVienRepository.h"

#include <utility>

LINKEDLISTNHANVIENREPOSITORY::Node::Node(
    std::unique_ptr<NHANVIEN> nhanVien)
    : data(std::move(nhanVien)), next(nullptr) {}

LINKEDLISTNHANVIENREPOSITORY::LINKEDLISTNHANVIENREPOSITORY()
    : head(nullptr), tail(nullptr), soLuongNhanVien(0) {}

LINKEDLISTNHANVIENREPOSITORY::~LINKEDLISTNHANVIENREPOSITORY() {
    while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

bool LINKEDLISTNHANVIENREPOSITORY::add(
    std::unique_ptr<NHANVIEN> nhanVien) {
    if (!nhanVien) {
        return false;
    }

    Node* newNode = new Node(std::move(nhanVien));
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    ++soLuongNhanVien;
    return true;
}

bool LINKEDLISTNHANVIENREPOSITORY::contains(
    const std::string& maNhanVien) const {
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaNhanVien() == maNhanVien) {
            return true;
        }
    }
    return false;
}

const NHANVIEN* LINKEDLISTNHANVIENREPOSITORY::findByMaNhanVien(
    const std::string& maNhanVien) const {
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaNhanVien() == maNhanVien) {
            return current->data.get();
        }
    }
    return nullptr;
}

bool LINKEDLISTNHANVIENREPOSITORY::update(
    const std::string& maNhanVien,
    std::unique_ptr<NHANVIEN> nhanVien) {
    if (!nhanVien || nhanVien->GetMaNhanVien() != maNhanVien) {
        return false;
    }

    for (Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaNhanVien() == maNhanVien) {
            current->data = std::move(nhanVien);
            return true;
        }
    }
    return false;
}

bool LINKEDLISTNHANVIENREPOSITORY::remove(
    const std::string& maNhanVien) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->data->GetMaNhanVien() == maNhanVien) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (tail == current) {
                tail = previous;
            }

            delete current;
            --soLuongNhanVien;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

std::vector<const NHANVIEN*>
LINKEDLISTNHANVIENREPOSITORY::getAll() const {
    std::vector<const NHANVIEN*> result;
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        result.push_back(current->data.get());
    }
    return result;
}

int LINKEDLISTNHANVIENREPOSITORY::getSoLuongNhanVien() const {
    return soLuongNhanVien;
}

void LINKEDLISTNHANVIENREPOSITORY::setSoLuongNhanVien(
    const int& soLuongNhanVienMoi) {
    soLuongNhanVien = soLuongNhanVienMoi;
}
