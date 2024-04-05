#include <iostream>
#include <cmath>

long long calculateFn(int n) {
    if (n == 1)
        return 3;
    else
        return pow(calculateFn(n - 1) + 2, calculateFn(n - 1) + 3);
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    long long result = calculateFn(n);
    std::cout << "f(" << n << ") = " << result << std::endl;

    return 0;
}
