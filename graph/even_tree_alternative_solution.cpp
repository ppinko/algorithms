// https://www.hackerrank.com/challenges/even-tree/problem

#include <iostream>
#include <vector>

using namespace std;

struct Node{
	public:
		int num; // number of children
		int root; // parent
};

int main(){
	int N, M; //nodes, edges
	int x, y;
	int count = 0;
	cin >> N >> M;
	vector <Node> nodes = vector<Node>(N);	

    // setting number of children to 1 for each node
	for(int i = 0;i < N;i++){
		nodes[i].num = 1;
		nodes[i].root = -1;
	}

	// creating edges between nodes - setting parent nodes
	for(int i = 0;i < M;i++){
		cin >> x >> y;
		nodes[x-1].root = y-1;   
	}

	// calculating number of children for each node, bottom-up approach
	for(int i = N-1;i > 0;i--)
		if(nodes[i].root >= 0)
			nodes[nodes[i].root].num += nodes[i].num;

	// calculating all nodes with even number of children (excluding main root node)
	for(int i = 0;i < N;i++)
		if(nodes[i].root >= 0 && nodes[i].num%2== 0)
			count ++;

	cout << count;

	return 0;
}