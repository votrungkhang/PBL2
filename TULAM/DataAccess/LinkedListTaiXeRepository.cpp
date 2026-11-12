#include "LinkedListTaiXeRepository.h"

#include <utility>

LINKEDLISTTAIXEREPOSITORY::Node::Node(std::unique_ptr<TAIXE> taiXe)
    : data(std::move(taiXe)), next(nullptr) {}

LINKEDLISTTAIXEREPOSITORY::LINKEDLISTTAIXEREPOSITORY()
    : head(nullptr), tail(nullptr), soLuongTaiXe(0) {}

LINKEDLISTTAIXEREPOSITORY::~LINKEDLISTTAIXEREPOSITORY() {
    while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

bool LINKEDLISTTAIXEREPOSITORY::add(std::unique_ptr<TAIXE> taiXe) {
    if (!taiXe) {
        return false;
    }

    Node* newNode = new Node(std::move(taiXe));
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    ++soLuongTaiXe;
    return true;
}

bool LINKEDLISTTAIXEREPOSITORY::contains(
    const std::string& maTaiXe) const {
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaTaiXe() == maTaiXe) {
            return true;
        }
    }
    return false;
}

const TAIXE* LINKEDLISTTAIXEREPOSITORY::findByMaTaiXe(
    const std::string& maTaiXe) const {
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaTaiXe() == maTaiXe) {
            return current->data.get();
        }
    }
    return nullptr;
}

bool LINKEDLISTTAIXEREPOSITORY::update(
    const std::string& maTaiXe,
    std::unique_ptr<TAIXE> taiXe) {
    if (!taiXe || taiXe->GetMaTaiXe() != maTaiXe) {
        return false;
    }

    for (Node* current = head;
         current != nullptr;
         current = current->next) {
        if (current->data->GetMaTaiXe() == maTaiXe) {
            current->data = std::move(taiXe);
            return true;
        }
    }
    return false;
}

bool LINKEDLISTTAIXEREPOSITORY::remove(const std::string& maTaiXe) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->data->GetMaTaiXe() == maTaiXe) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (tail == current) {
                tail = previous;
            }

            delete current;
            --soLuongTaiXe;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

std::vector<const TAIXE*> LINKEDLISTTAIXEREPOSITORY::getAll() const {
    std::vector<const TAIXE*> result;
    for (const Node* current = head;
         current != nullptr;
         current = current->next) {
        result.push_back(current->data.get());
    }
    return result;
}

int LINKEDLISTTAIXEREPOSITORY::getSoLuongTaiXe() const {
    return soLuongTaiXe;
}

void LINKEDLISTTAIXEREPOSITORY::setSoLuongTaiXe(
    const int& soLuongTaiXeMoi) {
    soLuongTaiXe = soLuongTaiXeMoi;
}
