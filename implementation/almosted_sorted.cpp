// https://www.hackerrank.com/challenges/almost-sorted/problem

#include <bits/stdc++.h>


using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    if (is_sorted(arr.cbegin(), arr.cend()))
        cout << "yes" << endl;
    else {
        decltype(auto) sorted {arr};
        sort(sorted.begin(), sorted.end());
        vector<pair<int, int>> original {};
        vector<pair<int, int>> sor {};
        for (int i = 0; i < arr.size(); ++i){
            if (arr.at(i) != sorted.at(i)){
                original.push_back(make_pair(i, arr.at(i)));
                sor.push_back(make_pair(i, sorted.at(i)));
            }
        }
        if (original.size() == 2 && original.at(0).second == sor.at(1).second && 
            original.at(1).second == sor.at(0).second){
                cout << "yes" << endl;
                cout << "swap " << original.at(0).first + 1 << " " << original.at(1).first + 1<< endl;
        }
        else {
            int a = original.front().first;
            int b = original.back().first;
            // cout << a << " : " << b << endl;
            reverse(arr.begin() + a, arr.begin() + b+1);
            if (is_sorted(arr.cbegin(), arr.cend())){
                cout << "yes" << endl;
                cout << "reverse " << a + 1 << " " << b + 1<< endl;
            }
            else 
                cout << "no" << endl;
        }
    }
}

int main()
{
    // int n;
    // cin >> n;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // string arr_temp_temp;
    // getline(cin, arr_temp_temp);

    // vector<string> arr_temp = split_string(arr_temp_temp);

    // vector<int> arr(n);

    // for (int i = 0; i < n; i++) {
    //     int arr_item = stoi(arr_temp[i]);

    //     arr[i] = arr_item;
    // }

    // almostSorted(arr);

    almostSorted({1, 5, 4, 3, 2, 6});

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
