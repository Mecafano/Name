#include <iostream>
#include <iomanip>

double seriesSum(int n) {
    if (n == 1)
        return 1.0;
    else if (n % 2 == 0)
        return seriesSum(n - 1) - 1.0 / n;
    else
        return seriesSum(n - 1) + 1.0 / n;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    double result = seriesSum(n);
    std::cout << "Sum of first " << n << " terms: " << std::fixed << std::setprecision(4) << result << std::endl;

    return 0;
}
