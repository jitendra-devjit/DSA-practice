#include <iostream>
#include <vector>
using namespace std;

int getFloor(vector<int>& a, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x) {
            ans = a[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int getCeil(vector<int>& a, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x) {
            ans = a[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int>& a, int n, int x) {
    int f = getFloor(a, n, x);
    int c = getCeil(a, n, x);
    return {f, c};
}

int main() {
    
    vector<int> a = {1, 2, 4, 6, 10, 12, 18};
    int x = 5;
    int n = a.size();

    pair<int, int> result = getFloorAndCeil(a, n, x);

   
    cout << "For x = " << x << " in array: ";
    for (int num : a) cout << num << " ";
    cout << "\nFloor = " << result.first << ", Ceil = " << result.second << endl;

    return 0;
}
