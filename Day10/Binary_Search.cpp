#include <iostream>
#include <vector>
using namespace std;


int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevent overflow
        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int main() {
    
    vector<int> nums = {-10, -3, 0, 5, 9, 12};
    int target = 9;

    int result = search(nums, target);

    
    cout << "Index of " << target << " is: " << result << endl;

    return 0;
}
