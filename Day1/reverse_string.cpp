// reverse_string.cpp
// LeetCode: Reverse String
// Given a char array s, reverse it in-place.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;

        while (start < end) {
            // Swap the characters at start and end, then move inward
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "Before reverse: ";
    for (char c : s) cout << c << " ";
    cout << endl;

    sol.reverseString(s);

    cout << "After reverse: ";
    for (char c : s) cout << c << " ";
    cout << endl;

    return 0;
}
