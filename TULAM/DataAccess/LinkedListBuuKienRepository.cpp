#include "LinkedListBuuKienRepository.h"

#include <utility>

LinkedListBuuKienRepository::Node::Node(unique_ptr<BuuKien> buuKien)
    : data(move(buuKien)), next(nullptr) {}

LinkedListBuuKienRepository::LinkedListBuuKienRepository()
    : head(nullptr), tail(nullptr),soLuongBuuKien(0) {}

LinkedListBuuKienRepository::~LinkedListBuuKienRepository() {
    while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

bool LinkedListBuuKienRepository::add( unique_ptr<BuuKien> buuKien) {
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

bool LinkedListBuuKienRepository::contains(
    const string& maBuuKien) const {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->getMaBuuKien() == maBuuKien) {
            return true;
        }
    }
    return false;
}

const BuuKien* LinkedListBuuKienRepository::findByMaBuuKien(
    const string& maBuuKien) const {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->getMaBuuKien() == maBuuKien) {
            return current->data.get();
        }
    }
    return nullptr;
}

bool LinkedListBuuKienRepository::update(
    const string& maBuuKien,
    unique_ptr<BuuKien> buuKien) {
    if (!buuKien || buuKien->getMaBuuKien() != maBuuKien) {
        return false;
    }

    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->getMaBuuKien() == maBuuKien) {
            current->data = move(buuKien);
            return true;
        }
    }
    return false;
}

bool LinkedListBuuKienRepository::updateTrangThai(
    const string& maBuuKien,
    const string& trangThai) {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->getMaBuuKien() == maBuuKien) {
            current->data->setTrangThai(trangThai);
            return true;
        }
    }
    return false;
}

bool LinkedListBuuKienRepository::remove(const string& maBuuKien) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->data->getMaBuuKien() == maBuuKien) {
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

vector<const BuuKien*> LinkedListBuuKienRepository::getAll() const {
    vector<const BuuKien*> result;
    for (Node* current = head; current != nullptr; current = current->next) {
        result.push_back(current->data.get());
    }
    return result;
}

int LinkedListBuuKienRepository::getSoLuongBuuKien(){
    return soLuongBuuKien;
}

void LinkedListBuuKienRepository::setSoLuongBuuKien(const int& soLuongBKMoi){
    soLuongBuuKien=soLuongBKMoi;
}