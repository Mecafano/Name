#include <iostream>
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
    Node *root = new Node(100);
    root->left = new Node(50);
    root->right = new Node(150);

    root->left->left = new Node(25);
    root->left->right = new Node(75);
    root->right->left = new Node(125);
    root->right->right = new Node(175);

    root->left->leftL = new Leaf("Speed");
    root->left->rightL = new Leaf("Strength");
    root->right->leftL = new Leaf("Power");
    root->right->rightL = new Leaf("Vision");

    return root;
}

string traverseTree(Node *root, int n) {
    if (root == NULL) {
        return "Invalid decision tree!";
    }

    while (root != NULL) {
        if (n < root->value) {
            if (root->leftL != NULL)
                return root->leftL->msg;
            root = root->left;
        } else {
            if (root->rightL != NULL)
                return root->rightL->msg;
            root = root->right;
        }
    }
    return "Invalid decision tree!";
}

int main() {
    Node *root = buildTree();
    int n;
    cout << "Enter a value: ";
    cin >> n;
    cout << traverseTree(root, n) << endl;
    return 0;
}
