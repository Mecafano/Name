#include <iostream>
#include <vector>
using namespace std;

void replaceWithMax(vector<int> &arr) {
    int n = arr.size();
    int maxSoFar = arr[n - 1]; // Initialize the maximum value as the last element
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxSoFar) {
            maxSoFar = arr[i]; // Update the maximum value if the current element is greater
        }
        arr[i] = maxSoFar; // Replace each element with the maximum value encountered so far
    }
    arr[n - 1] = -1; // Replace the last element with -1
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " integer numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    replaceWithMax(arr);

    cout << "Output: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
