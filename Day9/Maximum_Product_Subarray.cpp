#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductSubarray(vector<int>& nums) {
    int globalMax = nums[0];
    int currentMax = nums[0];
    int currentMin = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        int num = nums[i];
        if (num < 0) swap(currentMax, currentMin);

        currentMax = max(num, currentMax * num);
        currentMin = min(num, currentMin * num);

        globalMax = max(globalMax, currentMax);
    }
    return globalMax;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};

    cout << "Maximum Product Subarray: " << maxProductSubarray(nums) << endl;
    return 0;
}
