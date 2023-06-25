#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, startNode;
vector<vector<int>> x;
vector<bool> visited;

void DFS(int curNode) {
	visited[curNode] = true;
	cout << curNode << ' ';
	for (int i = 0; i < x[curNode].size(); i++) {
		if (!visited[x[curNode][i]]) DFS(x[curNode][i]);
	}
}

void BFS(int startNode) {
	queue<int> qu;
	qu.push(startNode);
	visited[startNode] = true;

	while (!qu.empty()) {
		int temp = qu.front();
		qu.pop();
		cout << temp << ' ';
		for (int i = 0; i < x[temp].size(); i++) {
			if (!visited[x[temp][i]]) { 
				qu.push(x[temp][i]);
				visited[x[temp][i]] = true;
			}
		}
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < x[i].size(); j++) {
			cout << "x[" << i << "][" << j << "] = " << x[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> startNode;
	x.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int strNode, endNode;
		cin >> strNode >> endNode;
		x[strNode].push_back(endNode);
		x[endNode].push_back(strNode);
	}

	for (int i = 1; i <= N; i++) {
		sort(x[i].begin(), x[i].end());
	}

	DFS(startNode);
	cout << '\n';
	fill(visited.begin(), visited.end(), false);
	BFS(startNode);
}