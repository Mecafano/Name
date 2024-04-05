#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    int countLength(Node* current) {
        if (current == nullptr)
            return 0;
        return 1 + countLength(current->next);
    }

public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int length() {
        return countLength(head);
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    int num;
    char ch;

    std::cout << "Enter integer numbers followed by a character to terminate: ";
    while (std::cin >> num) {
        list.insert(num);
    }

    int listLength = list.length();
    std::cout << "Output: " << listLength << std::endl;

    return 0;
}
//
// Created by shohr on 4/5/2024.
//
