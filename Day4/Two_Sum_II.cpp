#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target)
            return {left + 1, right + 1}; // 1-based indexing
        else if (sum < target)
            left++;
        else
            right--;
    }

    return {}; // No pair found
}

int main() {
    int n, target;

    cout << "Enter number of elements (sorted): ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> result = twoSum(numbers, target);

    if (!result.empty())
        cout << "Indices (1-based): " << result[0] << " and " << result[1] << endl;
    else
        cout << "No pair found that adds to the target." << endl;

    return 0;
}
