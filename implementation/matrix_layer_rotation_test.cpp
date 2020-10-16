// https://www.hackerrank.com/challenges/matrix-rotation-algo/problem

#include <bits/stdc++.h>

using namespace std;

void rotateData(vector<vector<int>> &matrix, int row_start, 
    int row_end, int column_start, int column_end, int rotation){

    vector<int> v {};

    for (int i = row_start; i <= row_end; ++i){
        v.push_back(matrix.at(i).at(column_start));
    }
    if (column_end != column_start){
        for (int j = column_start+1; j <= column_end; ++j){
            v.push_back(matrix.at(row_end).at(j));
        }
    }
    if (row_start != row_end){
        for (int k = row_end-1; k >= row_start; --k){
            v.push_back(matrix.at(k).at(column_end));
        }
    }
    if (column_end - column_start > 1){
        for (int i = column_end-1; i >= column_start+1; --i){
            v.push_back(matrix.at(row_start).at(i));
        }
    }
    rotation %= v.size();
    rotate(v.rbegin(), v.rbegin() + rotation, v.rend());
    
    int index = 0;
    for (int i = row_start; i <= row_end; ++i){
        matrix.at(i).at(column_start) = v.at(index);
        ++index;
    }
    if (column_end != column_start){
        for (int j = column_start+1; j <= column_end; ++j){
            matrix.at(row_end).at(j) = v.at(index);
            ++index;
        }
    }
    if (row_start != row_end){
        for (int k = row_end-1; k >= row_start; --k){
            matrix.at(k).at(column_end) = v.at(index);
            ++index;
        }
    }
    if (column_end - column_start > 1){
        for (int i = column_end-1; i >= column_start+1; --i){
            matrix.at(row_start).at(i) = v.at(index);
            ++index;
        }
    }
}

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    
    const int rows = matrix.size();
    const int columns = matrix.at(0).size();

    // one element matrix
    if (matrix.size() == 1 && matrix.at(0).size() == 1)
        cout << matrix.at(0).at(0) << endl;

    int row_start = 0, row_end = rows - 1;
    int column_start = 0, column_end = columns - 1;
    while (row_end >= row_start && column_end >= column_start){
        rotateData(matrix, row_start, row_end, column_start, column_end, r);
        --row_end; ++row_start; --column_end; ++column_start;
    }
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix.at(0).size(); ++j){
            if (j != matrix.at(0).size() -1)
                cout << matrix.at(i).at(j) << " ";
            else 
                cout << matrix.at(i).at(j) << endl;
        }   
    }
}

int main(){
    vector<vector<int>> vec {{1,2,3,4},{7,8,9,10},{13,14,15,16},{19,20,21,22},{25,26,27,28}};
    matrixRotation(vec, 7);

    cout << endl;

    return 0;
}