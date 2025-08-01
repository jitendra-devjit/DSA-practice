#include <iostream>
#include <vector>
using namespace std;

// Binary search to find first (occ = 0) or last (occ = 1) occurrence
int bSearch(const vector<int>& arr, int n, int x, int occ) {
    int start = 0, end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (x > arr[mid]) {
            start = mid + 1;
        } else if (x < arr[mid]) {
            end = mid - 1;
        } else {
            res = mid;
            if (occ == 0)
                end = mid - 1;  // Move left for first occurrence
            else
                start = mid + 1;  // Move right for last occurrence
        }
    }

    return res;
}

// Function to count total occurrences
int count(vector<int>& arr, int n, int x) {
    int first = bSearch(arr, n, x, 0);
    if (first == -1) return 0;  // Element not found

    int last = bSearch(arr, n, x, 1);
    return last - first + 1;
}

int main() {
    
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;
    int n = arr.size();


    int totalCount = count(arr, n, x);

    // Output result
    cout << "Element " << x << " appears " << totalCount << " times in the array." << endl;

    return 0;
}
