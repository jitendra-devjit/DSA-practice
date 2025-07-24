#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int>& nums) {
    int n = nums.size();
    vector<int> leaders;

    int maxRight = nums[n - 1];
    leaders.push_back(maxRight); // Last element is always a leader

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] >= maxRight) {
            leaders.push_back(nums[i]);
            maxRight = nums[i]; // Update max
        }
    }

    // Since we traversed from right to left, reverse to restore order
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> result = leaders(nums);

    cout << "Leaders in the array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
