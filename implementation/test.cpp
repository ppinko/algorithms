#include <bits/stdc++.h>

using namespace std;

int main(){
    string str {"12345"};
    // reverse(str.begin() + 1, str.begin() + 4);

    reverse(str.rbegin() + 1, str.rbegin() + 4);

    cout << str << endl;

    return 0;
}
