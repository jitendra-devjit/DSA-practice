#include<iostream>
#include<vector>
using namespace std;

// --------------- brute force approach --------------------

// void Set_Matrix_Zeroes(vector<vector<int>>& matrix){
//     int row = matrix.size();
//     int cols = matrix[0].size();

//     for(int i=0; i<row; i++){
//         for(int j=0; j<cols; j++){
//             if(matrix[i][j] == 0){
//                 // row 
//                 for(int k=0; k<cols; k++){
//                     if(matrix[i][k] != 0){
//                         matrix[i][k] = -1;
//                     }
//                 }
//                 // cols
//                 for(int k=0; k<row; k++){
//                     if(matrix[k][j] != 0){
//                         matrix[k][j] = -1;
//                     }
//                 }
//             }
//         }
//     }
//     for(int i=0; i<row; i++){
//         for(int j=0; j<cols; j++){
//             if(matrix[i][j] == -1){
//                 matrix[i][j] = 0;
//             }
//         }  
//     }      
// }

//-------------------------------------------------------------------------

// ------------------------better approach------------------
void Set_Matrix_Zeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int>row(rows,0); //m
    vector<int>col(cols,0); //n
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){
    vector<vector<int>>mat = {{1,2,3},     
                              {4,0,6},
                              {7,6,9}};
    Set_Matrix_Zeroes(mat);

    cout << "Matrix after setting zeroes:\n";
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}