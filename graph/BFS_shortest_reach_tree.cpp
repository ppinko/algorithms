#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Function to create  an adjacency list
vector<list<int>> adjecency_list(const int nodes, const vector<vector<int>> &edges){
    // vector size is one element bigger than num of nodes to add empty '0' node
    vector<list<int>> L (nodes + 1, list<int>{});

    // traversing through edges, crearing undirectional connection
    for (const auto &v : edges){
        L.at(v.at(0)).push_back(v.at(1));
        L.at(v.at(1)).push_back(v.at(0));
    }
        
    return L;
} 

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    auto L = adjecency_list(n, edges);
    vector<int> answer (n + 1, -1);

    // using queue for storing next to visit and set for visited
    queue<int, list<int>> next_to_visit;
    next_to_visit.push(s);
    set<int> visited {};
    int path = 0;
    while (true){
        int q_size = next_to_visit.size();
        if (q_size == 0)
            break; // end of connections
        for (int i = 0; i < q_size; ++i){
            visited.insert(next_to_visit.front());
            for (const auto &el : L.at(next_to_visit.front())){
                if (visited.find(el) == visited.end()){
                    answer.at(el) = path +1;
                    next_to_visit.push(el);
                }
            }
            next_to_visit.pop();
        }
        ++path;
    }

    // remove starting node and first element - 'null'
    answer.erase(answer.begin() + s);
    answer.erase(answer.begin());

    for (auto &el : answer){
        if (el != -1)
            el *= 6;
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

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