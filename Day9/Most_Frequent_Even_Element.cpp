#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxFreq = 0, result = -1;

    for (int num : nums) {
        if (num % 2 == 0) {
            int count = ++freq[num];
            if (count > maxFreq || (count == maxFreq && num < result)) {
                maxFreq = count;
                result = num;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {0, 1, 2, 2, 4, 4, 1};

    int ans = mostFrequentEven(nums);
    cout << "Most Frequent Even: " << ans << endl;
    return 0;
}
