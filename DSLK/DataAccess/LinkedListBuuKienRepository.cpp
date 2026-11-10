#include "LinkedListBuuKienRepository.h"

#include <utility>

LinkedListBuuKienRepository::Node::Node(std::unique_ptr<BuuKien> buuKien)
    : data(std::move(buuKien)), next(nullptr) {}

LinkedListBuuKienRepository::LinkedListBuuKienRepository()
    : head(nullptr), tail(nullptr) {}

LinkedListBuuKienRepository::~LinkedListBuuKienRepository() {
    while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

bool LinkedListBuuKienRepository::add(std::unique_ptr<BuuKien> buuKien) {
    if (!buuKien) {
        return false;
    }

    Node* newNode = new Node(std::move(buuKien));
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return true;
    }

    tail->next = newNode;
    tail = newNode;
    return true;
}

bool LinkedListBuuKienRepository::contains(
    const std::string& maBuuKien) const {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data->getMaBuuKien() == maBuuKien) {
            return true;
        }
    }
    return false;
}

std::vector<const BuuKien*> LinkedListBuuKienRepository::getAll() const {
    std::vector<const BuuKien*> result;
    for (Node* current = head; current != nullptr; current = current->next) {
        result.push_back(current->data.get());
    }
    return result;
}
