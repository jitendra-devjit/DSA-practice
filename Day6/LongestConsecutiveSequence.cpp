#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    int ans = 0;

    // Step 1: Insert all elements into the set
    for (auto x : nums) {
        st.insert(x);
    }

    // Step 2: Check for sequence starting points
    for (int x : st) {
        // If (x - 1) not in set, then x is the start of a sequence
        if (!st.count(x - 1)) {
            int count = 1;
            int ele = x;

            // Step 3: Count consecutive elements
            while (st.count(ele + 1)) {
                count++;
                ele += 1;
            }

            // Step 4: Update maximum length
            ans = max(ans, count);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = longestConsecutive(nums);

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << "\nLongest Consecutive Sequence Length = " << result << endl;

    return 0;
}
