#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findSecondMaxElement(vector<int>& arr){
    int n = arr.size();
    int largest = arr[0], secondlargest = INT_MIN;
    for(int i=1;i<n;i++){
        if(largest < arr[i]){
            secondlargest = largest;
            largest = arr[i];
        }else if (arr[i] > secondlargest && arr[i] != largest) {
            secondlargest = arr[i];
        }
    }
    return secondlargest;
}

int main(){
    vector<int> arr = {12, 5, 8, 20, 7, 15};

    cout << "Array elements: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    int maxElement = findSecondMaxElement(arr);
    cout << "Maximum element in the array: " << maxElement << endl;

    return 0;
}