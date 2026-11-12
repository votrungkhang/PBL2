#include "LinkedListBuuKienRepository.h"

#include <utility>

LINKEDLISTBUUKIENREPOSITORY::Node::Node(unique_ptr<BUUKIEN> buuKien)
    : data(move(buuKien)), next(nullptr) {}

LINKEDLISTBUUKIENREPOSITORY::LINKEDLISTBUUKIENREPOSITORY()
    : head(nullptr), tail(nullptr),soLuongBuuKien(0) {}

LINKEDLISTBUUKIENREPOSITORY::~LINKEDLISTBUUKIENREPOSITORY() {
    while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

bool LINKEDLISTBUUKIENREPOSITORY::add( unique_ptr<BUUKIEN> buuKien) {
    if(!buuKien){
        return false;
    }

    Node* newNode = new Node(move(buuKien));
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    ++soLuongBuuKien;
    return true;
}

bool LINKEDLISTBUUKIENREPOSITORY::contains(
    const string& maBuuKien) const {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->GetMaBuuKien() == maBuuKien) {
            return true;
        }
    }
    return false;
}

const BUUKIEN* LINKEDLISTBUUKIENREPOSITORY::findByMaBuuKien(
    const string& maBuuKien) const {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->GetMaBuuKien() == maBuuKien) {
            return current->data.get();
        }
    }
    return nullptr;
}

bool LINKEDLISTBUUKIENREPOSITORY::update(
    const string& maBuuKien,
    unique_ptr<BUUKIEN> buuKien) {
    if (!buuKien || buuKien->GetMaBuuKien() != maBuuKien) {
        return false;
    }

    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->GetMaBuuKien() == maBuuKien) {
            current->data = move(buuKien);
            return true;
        }
    }
    return false;
}

bool LINKEDLISTBUUKIENREPOSITORY::updateTrangThai(
    const string& maBuuKien,
    const string& trangThai) {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->GetMaBuuKien() == maBuuKien) {
            current->data->SetTrangThai(trangThai);
            return true;
        }
    }
    return false;
}

bool LINKEDLISTBUUKIENREPOSITORY::remove(const string& maBuuKien) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->data->GetMaBuuKien() == maBuuKien) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (tail == current) {
                tail = previous;
            }

            delete current;
            --soLuongBuuKien;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

vector<const BUUKIEN*> LINKEDLISTBUUKIENREPOSITORY::getAll() const {
    vector<const BUUKIEN*> result;
    for (Node* current = head; current != nullptr; current = current->next) {
        result.push_back(current->data.get());
    }
    return result;
}

int LINKEDLISTBUUKIENREPOSITORY::getSoLuongBuuKien() const {
    return soLuongBuuKien;
}

void LINKEDLISTBUUKIENREPOSITORY::setSoLuongBuuKien(const int& soLuongBKMoi){
    soLuongBuuKien=soLuongBKMoi;
}