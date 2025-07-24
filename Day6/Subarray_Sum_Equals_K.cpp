#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixsum;
    prefixsum[0] = 1;  // Important: for cases where subarray itself = k

    int sum = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        // Check if (sum - k) exists in prefixsum
        if (prefixsum.find(sum - k) != prefixsum.end()) {
            count += prefixsum[sum - k];  // Add its frequency to count
        }

        // Store current prefix sum frequency
        prefixsum[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3};  
    int k = 3;

    int result = subarraySum(nums, k);

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << "\nK = " << k;
    cout << "\nTotal Subarrays with Sum = K: " << result << endl;

    return 0;
}
