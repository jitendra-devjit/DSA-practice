#include <iostream>
#include <vector>
using namespace std;

// Function to sort colors using Dutch National Flag algorithm
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0)
            swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1)
            mid++;
        else // nums[mid] == 2
            swap(nums[mid], nums[high--]);
    }
}

// Utility function to print vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0}; // Sample input

    cout << "Before Sorting: ";
    printVector(nums);

    sortColors(nums); // Call function

    cout << "After Sorting:  ";
    printVector(nums);

    return 0;
}
