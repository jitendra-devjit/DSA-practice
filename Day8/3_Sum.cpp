#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicates

        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) left++;  // Skip duplicates
                while (left < right && nums[right] == nums[right-1]) right--; // Skip duplicates
                left++; right--;
            }
            else if (sum < 0) left++;
            else right--;
        }
    }

    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};  
    vector<vector<int>> result = threeSum(nums);
    
    cout << "3-Sum Triplets: " << endl;
    for (auto triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
