#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

int maxSubArray(vector<int>& arr) {
    int maxSum = INT_MIN;
    int crrSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        crrSum += arr[i];          // Add current element to current sum
        if (crrSum > maxSum)       // Update maxSum if current sum is bigger
            maxSum = crrSum;
        if (crrSum < 0)            // If current sum is negative, reset it
            crrSum = 0;
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
    int result = maxSubArray(arr);

    cout << "Input: ";
    for (int x : arr) cout << x << " ";
    cout << "\nMaximum Subarray Sum = " << result << endl;

    return 0;
}
