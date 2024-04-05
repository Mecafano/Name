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

    void deleteDuplicatesUtil(Node* current) {
        if (current == nullptr || current->next == nullptr)
            return;

        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            deleteDuplicatesUtil(current);
        } else {
            deleteDuplicatesUtil(current->next);
        }
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

    void deleteDuplicates() {
        deleteDuplicatesUtil(head);
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    // Example 1
    list.insert(-1);
    list.insert(-1);
    list.insert(4);
    list.insert(20);
    list.insert(20);
    list.insert(20);
    list.insert(49);
    list.insert(53);
    list.insert(53);
    list.deleteDuplicates();
    std::cout << "Output: ";
    list.display();

    // Example 2
    LinkedList list2;
    list2.insert(100);
    list2.insert(100);
    list2.deleteDuplicates();
    std::cout << "Output: ";
    list2.display();

    return 0;
}
