// https://www.hackerrank.com/challenges/two-pluses/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    vector<int> v {};
    int answer = 0, len = 0;
    const int rows = grid.size();
    const int columns = grid.at(0).size();

    for (int m = 0; m < 2; ++m){
        int max_val = 0;
        pair<int, int> max_cord {0, 0};
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < columns; ++j){
                if (grid.at(i).at(j) == 'G'){
                    int temp = 1;
                    int k = 1;
                    while (i - k >= 0 && i + k <= rows - 1 && j - k >= 0 && j + k <= columns - 1){
                        if (grid.at(i-k).at(j) == 'G' && grid.at(i+k).at(j) == 'G' && grid.at(i).at(j-k) == 'G' && grid.at(i).at(j+k) == 'G'){
                            temp += 4;
                            ++k;
                        }
                        else
                            break;
                    }
                    if (temp > max_val){
                        max_val = temp;
                        len = k-1;
                        max_cord = make_pair(i, j);
                    }
                }
            }   
        }
        cout << "MAX = " << max_val << " cordinates " << max_cord.first << "," << max_cord.second << endl;
        v.push_back(max_val);
        if (m == 0){
            grid.at(max_cord.first).at(max_cord.second) = 'B';
            while (len > 0){
                grid.at(max_cord.first - len).at(max_cord.second) = 'B';
                grid.at(max_cord.first + len).at(max_cord.second) = 'B';
                grid.at(max_cord.first).at(max_cord.second - len) = 'B';
                grid.at(max_cord.first).at(max_cord.second + len) = 'B';
                --len;
            }
        }
    }
    answer = v.at(0);
    if (v.at(1) != 0)
        answer *= v.at(1);
    return answer;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    // string nm_temp;
    // getline(cin, nm_temp);

    // vector<string> nm = split_string(nm_temp);

    // int n = stoi(nm[0]);

    // int m = stoi(nm[1]);

    // vector<string> grid(n);

    // for (int i = 0; i < n; i++) {
    //     string grid_item;
    //     getline(cin, grid_item);

    //     grid[i] = grid_item;
    // }

    // int result = twoPluses(grid);

    // fout << result << "\n";

    // fout.close();

    // cout << twoPluses({ "BGBBGB",
    //                     "GGGGGG",
    //                     "BGBBGB",
    //                     "GGGGGG",
    //                     "BGBBGB",
    //                     "BGBBGB"}) << endl;

    cout << twoPluses({ "GGGGGGGG",
                        "GBGBGGBG",
                        "GBGBGGBG",
                        "GGGGGGGG",
                        "GBGBGGBG",
                        "GGGGGGGG",
                        "GBGBGGBG",
                        "GGGGGGGG"}) << endl;

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
