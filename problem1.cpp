#include <iostream>
#include <string>
using namespace std;

class Leaf {
public:
    string msg;
    Leaf(string msg) {
        this->msg = msg;
    }
};

class Node {
public:
    int value;
    Node *left;
    Node *right;
    Leaf *leftL;
    Leaf *rightL;
    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
        leftL = NULL;
        rightL = NULL;
    }
};

Node* buildTree() {
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    root->left->leftL = new Leaf("Value is less than 2");
    root->left->rightL = new Leaf("Value is less than 2");
    root->right->leftL = new Leaf("Value is greater than or equal to 2");
    root->right->rightL = new Leaf("Value is greater than or equal to 2");

    return root;
}

void traverseTree(Node *root, int n) {
    if (root == NULL) {
        cout << "Invalid decision tree!" << endl;
        return;
    }

    while (root != NULL) {
        if (n < root->value) {
            if (root->leftL != NULL)
                cout << root->leftL->msg << endl;
            root = root->left;
        } else {
            if (root->rightL != NULL)
                cout << root->rightL->msg << endl;
            root = root->right;
        }
    }
}

int main() {
    Node *root = buildTree();
    int n;
    cout << "Enter a value: ";
    cin >> n;
    traverseTree(root, n);
    return 0;
}
