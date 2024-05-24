#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int>> x;
vector<bool> visited;

void DFS(int strNode) {
	visited[strNode] = true;
	cout << strNode << ' ';
	for (int temp : x[strNode]) {
		if (visited[temp]) continue;
		DFS(temp);
	}
}

void BFS(int strNode) {
	queue<int> qu;
	qu.push(strNode);
	visited[strNode] = true;
	while (!qu.empty()) {
		int temp = qu.front();
		cout << temp << ' ';
		qu.pop();
		for (int dist : x[temp]) {
			if (visited[dist]) continue;
			qu.push(dist);
			visited[dist] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M >> V;
	x.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int str, end;
		cin >> str >> end;
		x[str].push_back(end);
		x[end].push_back(str);
	}

	for (int i = 1; i <= N; i++) {
		sort(x[i].begin(), x[i].end());
	}
	DFS(V);
	fill(visited.begin(), visited.end(), false);
	cout << '\n';
	BFS(V);
}