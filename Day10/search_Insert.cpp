#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    int ans = n;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] >= target)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {1, 3, 5, 6};
    int target = 5;


    int index = searchInsert(nums, target);

    // Output the result
    cout << "Target " << target << " should be at index: " << index << endl;

    return 0;
}
