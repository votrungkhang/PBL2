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