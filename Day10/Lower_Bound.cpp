#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> nums, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    
    vector<int> nums = {1, 2, 4, 4, 5, 7, 9};
    int x = 4;
    int n = nums.size();

    int index = lowerBound(nums, n, x);

    // Output
    if (index < n)
        cout << "Lower bound of " << x << " is at index: " << index << " (value = " << nums[index] << ")" << endl;
    else
        cout << "Lower bound of " << x << " is not found in the array" << endl;

    return 0;
}
