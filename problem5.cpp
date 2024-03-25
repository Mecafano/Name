#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteDuplicates() {
        if (!head)
            return;

        unordered_set<int> seen;
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (seen.find(current->data) != seen.end()) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                seen.insert(current->data);
                prev = current;
                current = current->next;
            }
        }
    }

    void sort() {
        if (!head || !head->next)
            return;

        Node* current = head;
        Node* index = nullptr;
        int temp;

        while (current != nullptr) {
            index = current->next;
            while (index != nullptr) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        list.insert(data);
    }

    cout << "Original list: ";
    list.display();

    list.sort();
    list.deleteDuplicates();

    cout << "List after removing duplicates and sorting: ";
    list.display();

    return 0;
}
