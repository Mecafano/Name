#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const vector<int>& vec, int num) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == num) {
            return i; // Found the element, return its index
        }
    }
    return -1; // Element not found
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> elements(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    int num;
    cout << "Enter the number to search: ";
    cin >> num;

    int index = linearSearch(elements, num);
    if (index != -1) {
        cout << "The number " << num << " is found at index: " << index << endl;
    } else {
        cout << "The number " << num << " is not found in the vector." << endl;
    }

    return 0;
}
