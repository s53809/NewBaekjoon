#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> x;
vector<bool> visited;

int BFS(int startPos) {
	queue<int> qu;
	qu.push(startPos);
	visited[startPos] = true;
	int ans = 0;
	while (!qu.empty()) {
		int dist = qu.front();
		qu.pop();
		ans++;
		for (int i = 0, x_size = x[dist].size(); i < x_size; i++) {
			if (!visited[x[dist][i]]) {
				visited[x[dist][i]] = true;
				qu.push(x[dist][i]);
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N + 1);
	visited.resize(N + 1);
	vector<int> ansList(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		x[b].push_back(a);
	}

	int maxNum = 0;
	for (int i = 1; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);
		ansList[i] = BFS(i);
		maxNum = max(ansList[i], maxNum);
	}

	for (int i = 1; i <= N; i++) {
		if (maxNum == ansList[i]) cout << i << ' ';
	}


}