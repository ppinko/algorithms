// https://www.hackerrank.com/challenges/kruskalmstrsub/problem

#include <bits/stdc++.h>

using namespace std;

int kruskals(int nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight);
bool bfs_search(const int start_node, const int end_node, const vector<vector<int>> &L);

struct Node{
    public:
        int n_from;
        int n_to;
        int weight;

        Node(int from, int to, int w): n_from{from}, n_to{to}, weight{w} {}
};

// Breadth First Search function
bool bfs_search(const int start_node, const int end_node, const vector<vector<int>> &L){
    // checking self node assignment
    if (start_node == end_node)
        return false;
    
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
                return true;

            visited.insert(next_to_visit.front());
            for (const auto &el : L.at(next_to_visit.front())){
                if (visited.find(el) == visited.end())
                    next_to_visit.push(el);
            }
            next_to_visit.pop();
        }
        ++path;
    }
    return false; // connection not found 
}

int kruskals(int nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    
    vector<Node> vec {};
    for (int i = 0; i < g_from.size(); ++i)
        vec.push_back(Node(g_from[i], g_to[i], g_weight[i]));
    sort(vec.begin(), vec.end(), [](Node n1, Node n2) {return n1.weight < n2.weight;});

    vector<vector<int>> edges (nodes + 1, vector<int>{});
    int total = 0;

    for (const auto &N : vec){
        if (!bfs_search(N.n_from, N.n_to, edges)){
            total += N.weight;
            edges[N.n_from].push_back(N.n_to);
            edges[N.n_to].push_back(N.n_from);
        }
    }

    return total;
}

int main(){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    int from, to, w;
    vector<int> g_from, g_to, g_weight;
    for (int i = 0; i < num_edges; ++i){
        cin >> from >> to >> w;
        g_from.push_back(from);
        g_to.push_back(to);
        g_weight.push_back(w);
    }

    /*
    Output for test case 1 (Kruskal_input_1.txt) shoud equal 12.
    Output for test case 2 (Kruskal_input_2.txt) shoud equal 150.
    */

    cout << kruskals(num_nodes, g_from, g_to, g_weight) << endl;

    return 0;
}