#include <iostream>
#include <vector>
using namespace std;

int bSearch(vector<int>& arr, int n, int k, int occ) {
    int start = 0, end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;  // Find mid

        if (k > arr[mid]) {
            start = mid + 1;
        } else if (k < arr[mid]) {
            end = mid - 1;
        } else {
            res = mid;
            if (occ == 0)
                end = mid - 1;  // First occurrence
            else
                start = mid + 1;  // Last occurrence
        }
    }
    return res;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = bSearch(arr, n, k, 0);  // First occurrence
    int last = bSearch(arr, n, k, 1);   // Last occurrence
    return {first, last};
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int k = 2;
    int n = arr.size();

  
    pair<int, int> result = firstAndLastPosition(arr, n, k);


    cout << "First and last positions of " << k << " are: ";
    cout << result.first << " " << result.second << endl;

    return 0;
}
