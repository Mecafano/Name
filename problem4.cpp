#include <iostream>
#include <string>

using namespace std;

void printTriangle(int n) {
    for (int i = n; i > 0; --i) {
        cout << string(i, '*') << endl;
    }
}

void printSquare(int n) {
    for (int i = 0; i < n; ++i) {
        cout << string(n, '*') << endl;
    }
}

void squareValue(int n) {
    cout << n * n << endl;
}

int main() {
    int n;
    cout << "Enter a value for n: ";
    cin >> n;

    cout << "Triangle Pattern:" << endl;
    printTriangle(n);

    cout << "\nSquare Pattern:" << endl;
    printSquare(n);

    cout << "\nSquare value of " << n << endl;
    squareValue(n);

    return 0;
}
