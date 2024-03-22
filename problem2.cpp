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

    void insertAtPosition(int pos, int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        if (pos <= 1) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; current != NULL && i < pos - 1; i++) {
            current = current->next;
        }

        if (current == NULL)
            return;

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;

        if (newNode->next == NULL)
            tail = newNode;
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

    int value, pos;
    cout << "Enter the value and position of the new element: ";
    cin >> value >> pos;

    list.insertAtPosition(pos, value);

    cout << "Output: ";
    list.display();

    return 0;
}
