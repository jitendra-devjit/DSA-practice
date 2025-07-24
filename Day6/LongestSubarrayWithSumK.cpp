#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k) {
    unordered_map<int, int> prefixsum;
    int sum = 0;
    int maxlen = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        // Case 1: if sum from 0 to i is exactly k
        if (sum == k) {
            maxlen = i + 1;
        }

        // Case 2: if there exists a prefix sum that leads to sum = k
        if (prefixsum.find(sum - k) != prefixsum.end()) {
            int prevIndex = prefixsum[sum - k];
            maxlen = max(maxlen, i - prevIndex);
        }

        // Case 3: store first occurrence of sum
        if (prefixsum.find(sum) == prefixsum.end()) {
            prefixsum[sum] = i;
        }
    }

    return maxlen;
}

int main() {

    vector<int> nums = {-1, 1, 1, 0, 0, 1};
    int k = 2;

    int result = getLongestSubarray(nums, k);

    cout << "Input Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nTarget Sum (k): " << k << endl;
    cout << "Longest Subarray Length = " << result << endl;

    return 0;
}
