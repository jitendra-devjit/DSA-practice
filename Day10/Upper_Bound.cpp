#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int> &nums, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > x) {
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

 
    int index = upperBound(nums, x, n);

    // Output
    if (index < n)
        cout << "Upper bound of " << x << " is at index: " << index << " (value = " << nums[index] << ")" << endl;
    else
        cout << "All elements are less than or equal to " << x << endl;

    return 0;
}
