#include <iostream>
#include <climits>
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

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int maxElement() {
        if (head == NULL)
            return 0;
        int maxVal = INT_MIN;
        Node* temp = head;
        while (temp != NULL) {
            maxVal = max(maxVal, temp->data);
            temp = temp->next;
        }
        return maxVal;
    }

    int minElement() {
        if (head == NULL)
            return 0;
        int minVal = INT_MAX;
        Node* temp = head;
        while (temp != NULL) {
            minVal = min(minVal, temp->data);
            temp = temp->next;
        }
        return minVal;
    }

    int firstElement() {
        if (head == NULL)
            return 0;
        return head->data;
    }
};

int main() {
    LinkedList list;
    int num;
    cout << "Enter integers to insert into the list, and input a character to stop: ";
    while (cin >> num) {
        list.insertBack(num);
    }

    cout << "Maximum number: " << list.maxElement() << endl;
    cout << "First element: " << list.firstElement() << endl;
    cout << "Size of the list: " << list.size() << endl;
    cout << "Minimum element: " << list.minElement() << endl;

    return 0;
}
