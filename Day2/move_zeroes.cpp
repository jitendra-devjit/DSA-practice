#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int nonZeroIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[nonZeroIndex] = nums[i];
            nonZeroIndex++;
        }
    }
    for (int i = nonZeroIndex; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    return 0;
}
