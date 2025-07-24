#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    set<int> st;

    // Insert all elements from both arrays into the set
    for (int x : nums1) st.insert(x);
    for (int x : nums2) st.insert(x);

    // Now insert set elements into result vector (sorted & unique)
    vector<int> result;
    for (int x : st) {
        result.push_back(x);
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 4, 5, 6};

    vector<int> result = unionArray(nums1, nums2);

    cout << "Union of the two arrays: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
