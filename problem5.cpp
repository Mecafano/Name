#include <iostream>

void printFibonacciReverse(int n, int a = 0, int b = 1) {
    if (n <= 0)
        return;

    printFibonacciReverse(n - 1, b, a + b);
    std::cout << a << " ";
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::cout << "Fibonacci series in reverse order: ";
    printFibonacciReverse(n);

    return 0;
}
