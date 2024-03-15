#include <iostream>
#include <vector>

using namespace std;

void countSmaller(const vector<int>& sequence) {
    int n = sequence.size();
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (sequence[j] < sequence[i]) {
                count++;
            }
        }
        cout << count << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;

    vector<int> sequence(n);
    cout << "Enter the sequence of numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    cout << "Counts of smaller numbers for each value: ";
    countSmaller(sequence);

    return 0;
}
