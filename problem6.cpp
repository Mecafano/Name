#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int minDistance(vector<int>& nums, int x, int y) {
    int minDist = INT_MAX;
    int prev = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == x || nums[i] == y) {
            if (prev != -1 && nums[i] != nums[prev]) {
                minDist = min(minDist, i - prev);
            }
            prev = i;
        }
    }

    return minDist;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integer numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int x, y;
    cout << "Enter two numbers x and y: ";
    cin >> x >> y;

    int distance = minDistance(nums, x, y);

    cout << "Output: " << distance << endl;

    return 0;
}
