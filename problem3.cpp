#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertBack(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteAtPosition(int pos) {
        if (head == NULL)
            return;

        Node* current = head;
        for (int i = 1; current != NULL && i < pos; i++) {
            current = current->next;
        }

        if (current == NULL)
            return;

        if (current == head) {
            head = current->next;
            if (head != NULL)
                head->prev = NULL;
            delete current;
        } else {
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            delete current;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    LinkedList list;
    cout << "Enter " << n << " integer numbers: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.insertBack(num);
    }

    int pos;
    cout << "Enter the position of the element to delete: ";
    cin >> pos;

    list.deleteAtPosition(pos);

    cout << "Output: ";
    list.display();

    return 0;
}
