// https://www.hackerrank.com/challenges/matrix-rotation-algo/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void rotateData(vector<vector<int>> &matrix, int row_start, 
    int row_end, int column_start, int column_end);

void matrixRotation(vector<vector<int>> matrix, int r);

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

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}