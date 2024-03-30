#include <iostream>
#include <iomanip>
using namespace std;

double calculate_an(int n) {
    if (n == 1)
        return 4.0;
    else
        return (calculate_an(n - 1) - 1.0) / 2.0;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << fixed << setprecision(10);

    double result = calculate_an(n);
    cout << "a_" << n << " = " << result << endl;

    return 0;
}
