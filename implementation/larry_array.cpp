// https://www.hackerrank.com/challenges/larrys-array/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {
    for (int i = 0; i < A.size()-2; ++i){
        while(A.at(i) != i+1){
            auto it = find(A.begin(), A.end(), i+1);
            int pos = it - A.begin();
            if (pos - 2 > i - 1){
                if (pos - 2 >= 0)
                    rotate(A.begin() + pos - 2, A.begin()+ pos - 1, A.begin()+pos+1);
                else
                    rotate(A.begin(), A.begin()+1, A.begin()+3); 
            }       
            else {
                rotate(A.begin()+i, A.begin()+i+1, A.begin()+i+3);
            }
        }
    }
    if (is_sorted(A.begin(), A.end()))
        return "YES";
    else 
        return "NO";
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    // int t;
    // cin >> t;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // for (int t_itr = 0; t_itr < t; t_itr++) {
    //     int n;
    //     cin >> n;
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //     string A_temp_temp;
    //     getline(cin, A_temp_temp);

    //     vector<string> A_temp = split_string(A_temp_temp);

    //     vector<int> A(n);

    //     for (int i = 0; i < n; i++) {
    //         int A_item = stoi(A_temp[i]);

    //         A[i] = A_item;
    //     }

    //     string result = larrysArray(A);

    //     fout << result << "\n";
    // }

    // fout.close();

    cout << larrysArray({1, 3, 4, 2}) << endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}