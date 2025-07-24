#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;
    vector<int> result;

    // Separate positive and negative numbers
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    // Alternate positive and negative
    for (int i = 0; i < pos.size(); i++) {
        result.push_back(pos[i]);
        result.push_back(neg[i]);
    }

    return result;
}

int main() {
    
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> ans = rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
