// https://www.hackerrank.com/challenges/magic-square-forming/problem

#include <bits/stdc++.h>

using namespace std;

// function declarations
vector<vector<int>> rotateMatrix(const vector<vector<int>> &m);
int differenceMatrix(vector<vector<int>> &a, vector<vector<int>> &b);
int formingMagicSquare(vector<vector<int>> s);

// my additional rotation function
vector<vector<int>> rotateMatrix(const vector<vector<int>> &m){
    vector<vector<int>> rotated {};
    const int len = m.size();
    for (int i = 0; i < len; ++i){
        vector<int> row {};
        for (int j = len-1; j >= 0; --j){
            row.push_back(m.at(j).at(i));
        }
        rotated.push_back(row);
    }
    return rotated;
}

// my additional comparision function
int differenceMatrix(vector<vector<int>> &a, vector<vector<int>> &b){
    const size_t len = a.size();
    int total = 0;
    for (size_t i = 0; i < len; ++i){
        for (size_t j = 0; j < len; ++j){
            total += abs(a[i][j] - b[i][j]);
        }
    }
    return total;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    // magic squares possible positions
    vector<vector<int>> mag1 {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}};
    vector<vector<int>> mag2 {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}};
    int a = differenceMatrix(s, mag1);
    int b = differenceMatrix(s, mag2);
    int min_val = min(a, b);
    for (int i = 0; i < 3; ++i){
        mag1 = rotateMatrix(mag1);
        mag2 = rotateMatrix(mag2);
        a = differenceMatrix(s, mag1);
        b = differenceMatrix(s, mag2);
        if (min_val > min(a, b))
            min_val = min(a, b);
    }
    return min_val;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    // vector<vector<int>> s(3);
    // for (int i = 0; i < 3; i++) {
    //     s[i].resize(3);

    //     for (int j = 0; j < 3; j++) {
    //         cin >> s[i][j];
    //     }

    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

    // int result = formingMagicSquare(s);

    // fout << result << "\n";

    // fout.close();

    auto v = rotateMatrix({ {4,8,2}, 
                            {4,5,7}, 
                            {6,1,6}});
    for (int i = 0; i < v.size(); ++i){
        for (int j = 0; j < v.at(0).size(); ++j){
            if (j != v.at(0).size() -1)
                cout << v.at(i).at(j) << " ";
            else 
                cout << v.at(i).at(j) << endl;
        }   
    }

    cout << formingMagicSquare({{4,8,2}, {4,5,7}, {6,1,6}}) << endl;

    return 0;
}