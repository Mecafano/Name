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

    void deleteAllUtil(Node* current) {
        if (current == nullptr)
            return;

        std::cout << current->data << " is deleted" << std::endl;
        Node* nextNode = current->next;
        delete current;
        deleteAllUtil(nextNode);
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

    void deleteAll() {
        deleteAllUtil(head);
        head = nullptr; // Reset the head to nullptr after deleting all nodes
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

    std::cout << "Output:" << std::endl;
    list.deleteAll();

    return 0;
}
