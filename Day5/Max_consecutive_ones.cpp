#include <iostream>
#include <vector>
#include <algorithm> // for max()
using namespace std;

// Function to find the maximum number of consecutive 1s
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0;
    int maxcount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxcount = max(count, maxcount);
        }
        else
        {
            count = 0;
        }
    }
    return maxcount;
}

int main()
{
    // Sample input
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    // Print the input array
    cout << "Input Array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    // Function call and result
    int result = findMaxConsecutiveOnes(nums);
    cout << "Maximum Consecutive 1s: " << result << endl;

    return 0;
}
