// https://www.hackerrank.com/challenges/two-pluses/problem

#include <bits/stdc++.h>
#include <tuple>

using namespace std;

vector<string> split_string(string);

int not_overlap(vector<tuple<int, int, int, int>> &t){
    size_t len = t.size();
    vector<pair<int, int>> s2 {};
    int max_val = get<0>(t.at(0));
    for (int i = 0; i < len - 1; ++i){
        int val, x, y, power;
        tie(val, x, y, power) = t.at(i);
        vector<pair<int, int>> s1 {make_pair(x, y)};
        while (power > 0){
            s1.push_back(make_pair(x - power, y));
            s1.push_back(make_pair(x + power, y));
            s1.push_back(make_pair(x, y - power)); 
            s1.push_back(make_pair(x, y + power));
            --power;
        }
        int s1_size = s1.size();
        for (int j = i+1;j < len; ++j){
            int val2, x2, y2, power2;
            tie(val2, x2, y2, power2) = t.at(j);
            vector<pair<int, int>> s2 {make_pair(x2, y2)};
            while (power2 > 0){
                s2.push_back(make_pair(x2 - power2, y2));
                s2.push_back(make_pair(x2 + power2, y2));
                s2.push_back(make_pair(x2, y2 - power2)); 
                s2.push_back(make_pair(x2, y2 + power2));
                --power2;
            }
            bool flag = true;
            for (const auto &c : s2){
                for (const auto &d : s1){
                    if (c.first == d.first && c.second == d.second){
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }

            if (flag){
                if (val * val2 > max_val){
                    max_val = val * val2;
                    }
            }
        }
    }
    return max_val;
}

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    vector<tuple<int, int, int, int>> v {};
    vector<tuple<int, int, int, int>> ones {};
    int answer = 0, len = 0;
    const int rows = grid.size();
    const int columns = grid.at(0).size();

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
                if (temp == 1)
                    ones.push_back(make_tuple(temp, i, j, k-1));
                else {
                    while (temp > 1){
                        v.push_back(make_tuple(temp, i, j, k-1));
                        temp -= 4;
                        --k;
                    }
                }
            }
        }   
    }
    if (v.size() == 0 && ones.size() > 0)
        return 1;
    else if (v.size() == 0 && ones.size() == 0)
        return 0;
    sort(v.begin(), v.end(), [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {return get<0>(a) > get<0>(b);} );
    return not_overlap(v);
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

    // cout << twoPluses({ "BGBBB",
    //                     "GGGGB",
    //                     "BGGGG",
    //                     "BBBGB"}) << endl;    

    return 0;
}

// vector<string> split_string(string input_string) {
//     string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
//         return x == y and x == ' ';
//     });

//     input_string.erase(new_end, input_string.end());

//     while (input_string[input_string.length() - 1] == ' ') {
//         input_string.pop_back();
//     }

//     vector<string> splits;
//     char delimiter = ' ';

//     size_t i = 0;
//     size_t pos = input_string.find(delimiter);

//     while (pos != string::npos) {
//         splits.push_back(input_string.substr(i, pos - i));

//         i = pos + 1;
//         pos = input_string.find(delimiter, i);
//     }

//     splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

//     return splits;
// }
