#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	vector<int> adjNode;
	vector<int> reverseAdjNode;
};

int N, M;
vector<Node> node;
vector<vector<int>> x;

void DFS(int tamsekNum, int startPos) {
	for (int i = 0; i < node[startPos].adjNode.size(); i++) {
		if (x[tamsekNum][node[startPos].adjNode[i]] == 0) {
			x[tamsekNum][node[startPos].adjNode[i]] = 1;
			DFS(tamsekNum, node[startPos].adjNode[i]);
		}
	}
}

void DeFS(int tamsekNum, int startPos) {
	for (int i = 0; i < node[startPos].reverseAdjNode.size(); i++) {
		if (x[tamsekNum][node[startPos].reverseAdjNode[i]] == 0) {
			x[tamsekNum][node[startPos].reverseAdjNode[i]] = 1;
			DeFS(tamsekNum, node[startPos].reverseAdjNode[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	node.resize(N + 1);
	x.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		node[a].adjNode.push_back(b);
		node[b].reverseAdjNode.push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		x[i].resize(N + 1);
		fill(x[i].begin(), x[i].end(), 0);
		x[i][i] = 1;
		DFS(i, i);
		DeFS(i, i);
		int count = 0;
		for (int j = 1; j <= N; j++) {
			if (x[i][j] == 0)count++;
		}
		cout << count << '\n';
	}
	
}