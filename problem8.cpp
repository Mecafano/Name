#include <iostream>

using namespace std;

string canDivideCake(int a, int b, int N) {

    if (a >= N || b >= N)
        return "YES";


    if (a % 2 == 0 && b % 2 == 0) {

        while (a % 2 == 0 && b % 2 == 0) {
            a /= 2;
            b /= 2;
            if (a >= N || b >= N)
                return "YES";
        }
    }


    if (a % 2 == 0 && a / 2 >= N)
        return "YES";
    if (b % 2 == 0 && b / 2 >= N)
        return "YES";

    return "NO";
}

int main() {
    int a, b, N;
    cout << "Enter the dimensions of the cake (a b): ";
    cin >> a >> b;
    cout << "Enter the number of people (N): ";
    cin >> N;

    string result = canDivideCake(a, b, N);
    cout << "Output: " << result << endl;

    return 0;
}
