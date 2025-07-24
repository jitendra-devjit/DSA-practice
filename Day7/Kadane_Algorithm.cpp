#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

// Function to find maximum subarray sum
int maxSubArray(vector<int>& nums) {
    int currsum = 0;
    int maxsum = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        currsum += nums[i];

        if (currsum > maxsum) {
            maxsum = currsum;
        }

        if (currsum < 0) {
            currsum = 0;
        }
    }

    return maxsum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);

    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}
