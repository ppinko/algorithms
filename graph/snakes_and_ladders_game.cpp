// https://www.hackerrank.com/challenges/the-quickest-way-up/problem

#include <bits/stdc++.h>

using namespace std;

// Breadth First Search function
int bfs_search(const int start_node, const int end_node, const vector<vector<int>> &L){
    // checking self node assignment
    if (start_node == end_node)
        return 0;
    
    // using queue for storing next to visit and set for visited
    queue<int> next_to_visit;
    next_to_visit.push(start_node);
    set<int> visited {};
    int path = 0;
    while (true){
        int q_size = next_to_visit.size();
        if (q_size == 0)
            break; // connection not found 
        for (int i = 0; i < q_size; ++i){
            if (next_to_visit.front() == end_node)
                return path;

            visited.insert(next_to_visit.front());
            for (const auto &el : L.at(next_to_visit.front())){
                if (visited.find(el) == visited.end())
                    next_to_visit.push(el);
            }
            next_to_visit.pop();
        }
        ++path;
    }
    return -1; // connection not found 
}

int quickestWayUp(const vector<vector<int>> &ladders, const vector<vector<int>> &snakes) {
    // creating adjacency table
    // firstly, all possible rolles of dice from any place
    vector<vector<int>> L (101, vector<int>{});
    for (int i = 1; i <= 99; ++i){
        for(int j = 1; j <= 6; ++j){
            if (i+j <= 100)
                L.at(i).push_back(i+j);
        }
    }
    // secondly, ladders and snakes
    vector<vector<vector<int>>> all;
    all.push_back(ladders);
    all.push_back(snakes);
    for (const auto &group : all){
        for (const auto &edge : group){
            // cout << "-" << edge[0] << "-" << edge[1] << "-\n"; 
            L.at(edge[0]).push_back(edge[1]);
        }
    }

    return bfs_search(1, 100, L);
}

int main(){

    int tests, num_ladders, num_snakes;
    cin >> tests;
    for (int i = 0; i < tests; ++i){
        vector<vector<int>> ladders{};
        cin >> num_ladders;
        for (int j = 0; j < num_ladders; ++j){
            int from, to;
            cin >> from >> to;
            ladders.push_back({from, to});
        }
        vector<vector<int>> snakes{};
        cin >> num_snakes;
        for (int j = 0; j < num_snakes; ++j){
            int from, to;
            cin >> from >> to;
            snakes.push_back({from, to});
        }
        cout << quickestWayUp(ladders, snakes) << endl;;
    }
    

    /*
    Output for test case 1 (Kruskal_input_1.txt) shoud equal 12.
    Output for test case 2 (Kruskal_input_2.txt) shoud equal 150.
    */


    return 0;
}