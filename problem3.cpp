#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortAroundValue(vector<int> &arr, int v) {
    int n = arr.size();
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == v) {
            index = i;
            break;
        }
    }

    sort(arr.begin(), arr.begin() + index, greater<int>());

    sort(arr.begin() + index + 1, arr.end());
}

int main() {
    int n, v;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> v;

    sortAroundValue(arr, v);

    // Print the sorted array
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
