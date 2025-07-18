#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> map;

    // Store all elements with their index
    for (int i = 0; i < n; i++) {
        map[nums[i]] = i;
    }

    // Find the required pair
    for (int i = 0; i < n; i++) {
        int req = target - nums[i];
        if (map.count(req) && i != map[req]) {
            return {i, map[req]};
        }
    }

    return {-1, -1}; // If no pair found
}

int main() {
    int n, target;
    
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (result[0] != -1)
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    else
        cout << "No two numbers found that sum to target." << endl;

    return 0;
}
