#ifndef DSLK_H
#define DSLK_H
#include <iostream>
#include "BuuKien.h"

using namespace std;

class LinkedList {
private:
    struct Node {
        BuuKien* data;
        Node* next;

        Node(BuuKien* BK) {
            data=BK;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // 1. Them Node vao cuoi danh sach
    void pushBack(BuuKien* BK) {
        Node* newNode = new Node(BK);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    // 2. Tim kiem Node theo gia tri
    bool search(string maBuuKien) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data->getMaBuuKien() == maBuuKien) {
                return true;
            }

            current = current->next;
        }
        return false;
    }

    // 3. Xoa Node dau tien co gia tri value
    bool remove(string maBuuKien) {
        if (head == nullptr) {
            return false;
        }

        if (head->data->getMaBuuKien() == maBuuKien) {
            Node* temp = head;
            head = head->next;

            if (head == nullptr) {
                tail = nullptr;
            }

            delete temp;
            return true;
        }

        Node* current = head;

        while (current->next != nullptr &&
               current->next->data->getMaBuuKien() != maBuuKien) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return false;
        }

        Node* temp = current->next;
        current->next = temp->next;

        if (temp == tail) {
            tail = current;
        }

        delete temp;
        return true;
    }

    

    // Cap nhat ma buu kien
    bool update(string maCu, string maMoi) {
        Node* current = head;

        // Kiem tra ma moi da ton tai chua
        if (maMoi.empty()) {
            return false;
        }

        if (maCu != maMoi && search(maMoi)) {
            return false;
        }

        // Duyet danh sach
        while (current != nullptr) {

            if (current->data->getMaBuuKien() == maCu) {

                current->data->setMaBuuKien(maMoi);

                return true;
            }

            current = current->next;
        }

        return false;
    }
    // 5. Hien thi danh sach
    void display() {
        Node* current = head;

        while (current != nullptr) {
            current->data->Show();
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Ngan sao chep de tranh loi quan ly bo nho
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
};

#endif