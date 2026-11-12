#include "LinkedListKhachHangRepository.h"

#include <utility>

LINKEDLISTKHACHHANGREPOSITORY::Node::Node(
    std::unique_ptr<KHACHHANG> khachHang)
    : data(std::move(khachHang)), next(nullptr) {}

LINKEDLISTKHACHHANGREPOSITORY::LINKEDLISTKHACHHANGREPOSITORY()
    : head(nullptr), tail(nullptr), soLuongKhachHang(0) {}

LINKEDLISTKHACHHANGREPOSITORY::~LINKEDLISTKHACHHANGREPOSITORY() {
    while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

bool LINKEDLISTKHACHHANGREPOSITORY::add(
    std::unique_ptr<KHACHHANG> khachHang) {
    if (!khachHang) {
        return false;
    }

    Node* newNode = new Node(std::move(khachHang));
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    ++soLuongKhachHang;
    return true;
}

bool LINKEDLISTKHACHHANGREPOSITORY::contains(
    const std::string& maKhachHang) const {
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaKhachHang() == maKhachHang) {
            return true;
        }
    }
    return false;
}

const KHACHHANG* LINKEDLISTKHACHHANGREPOSITORY::findByMaKhachHang(
    const std::string& maKhachHang) const {
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaKhachHang() == maKhachHang) {
            return current->data.get();
        }
    }
    return nullptr;
}

bool LINKEDLISTKHACHHANGREPOSITORY::update(
    const std::string& maKhachHang,
    std::unique_ptr<KHACHHANG> khachHang) {
    if (!khachHang || khachHang->GetMaKhachHang() != maKhachHang) {
        return false;
    }

    for (Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaKhachHang() == maKhachHang) {
            current->data = std::move(khachHang);
            return true;
        }
    }
    return false;
}

bool LINKEDLISTKHACHHANGREPOSITORY::remove(
    const std::string& maKhachHang) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->data->GetMaKhachHang() == maKhachHang) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (tail == current) {
                tail = previous;
            }

            delete current;
            --soLuongKhachHang;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

std::vector<const KHACHHANG*>
LINKEDLISTKHACHHANGREPOSITORY::getAll() const {
    std::vector<const KHACHHANG*> result;
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        result.push_back(current->data.get());
    }
    return result;
}

int LINKEDLISTKHACHHANGREPOSITORY::getSoLuongKhachHang() const {
    return soLuongKhachHang;
}

void LINKEDLISTKHACHHANGREPOSITORY::setSoLuongKhachHang(
    const int& soLuongKhachHangMoi) {
    soLuongKhachHang = soLuongKhachHangMoi;
}