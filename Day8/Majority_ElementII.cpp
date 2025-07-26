#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0, num1 = 0, num2 = 1;
    for (int num : nums) {
        if (num == num1) count1++;
        else if (num == num2) count2++;
        else if (count1 == 0) { num1 = num; count1 = 1; }
        else if (count2 == 0) { num2 = num; count2 = 1; }
        else { count1--; count2--; }
    }

    count1 = count2 = 0;
    for (int num : nums) {
        if (num == num1) count1++;
        else if (num == num2) count2++;
    }

    vector<int> result;
    if (count1 > nums.size() / 3) result.push_back(num1);
    if (count2 > nums.size() / 3) result.push_back(num2);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 2, 1, 1};  // Predefined input
    vector<int> result = majorityElement(nums);
    cout << "Majority Elements (> n/3): ";
    for (int num : result) cout << num << " ";
    cout << endl;
    return 0;
}
