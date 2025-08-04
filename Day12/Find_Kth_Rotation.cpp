#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findKRotation(vector<int>& arr) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        } else {
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }

    return index;
}

int main() {
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << "Array is rotated " << findKRotation(arr) << " times" << endl;
    return 0;
}
