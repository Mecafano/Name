#include <iostream>

unsigned long long binomialCoefficient(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int main() {
    int n, k;
    std::cout << "Enter the values of n and k: ";
    std::cin >> n >> k;

    unsigned long long result = binomialCoefficient(n, k);
    std::cout << "Binomial Coefficient C(" << n << ", " << k << ") = " << result << std::endl;

    return 0;
}
