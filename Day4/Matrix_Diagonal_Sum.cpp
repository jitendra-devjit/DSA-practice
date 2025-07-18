#include<iostream>
#include<vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += mat[i][i]; // Primary diagonal
        if (i != n - i - 1)
            sum += mat[i][n - i - 1]; // Secondary diagonal (avoid double counting center)
    }
    
    return sum;
}

int main() {
    int n;
    cout << "Enter size of square matrix (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int result = diagonalSum(mat);
    cout << "Diagonal Sum = " << result << endl;

    return 0;
}
