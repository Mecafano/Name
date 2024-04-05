#include <iostream>
#include <iomanip>

double calculate_an(int n) {
    double a = 4.0;
    for (int i = 2; i <= n; ++i) {
        a = 1.0 / (2 * a - 1);
    }
    return a;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    double result = calculate_an(n);

    std::cout << std::fixed << std::setprecision(10);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
