// max_element_array.cpp
// Find the maximum element in an array using C++.

#include <iostream>
#include <vector>
using namespace std;

int findMaxElement(vector<int>& arr) {
    int n = arr.size();
    int maxElement = arr[0]; // Assume first element is the maximum initially

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; // Update if a larger element is found
        }
    }

    return maxElement;
}

int main() {
    vector<int> arr = {12, 5, 8, 20, 7, 15};

    cout << "Array elements: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    int maxElement = findMaxElement(arr);
    cout << "Maximum element in the array: " << maxElement << endl;

    return 0;
}
