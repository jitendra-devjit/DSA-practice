#include <iostream>
#include <vector>
using namespace std;

// Function to search in rotated sorted array
int search(vector<int>& nums, int k) {
    int n = nums.size();    
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == k) {
            return mid;
        }

        if (nums[low] <= nums[mid]) {
            // Left half is sorted
            if (nums[low] <= k && k <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // Right half is sorted
            if (nums[mid] <= k && k <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1; // Not found
}

int main() {
 
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

  
    int index = search(nums, target);


    if (index != -1)
        cout << "Element " << target << " found at index: " << index << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;

    return 0;
}
