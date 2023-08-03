#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> indegree(N + 1, 0);
	vector<vector<int>> x(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		indegree[b]++;
		x[a].push_back(b);
	}

	queue<int> qu;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) qu.push(i);
	}

	while (!qu.empty()) {
		int temp = qu.front(); qu.pop();
		cout << temp << ' ';

		for (int i = 0, x_size = x[temp].size(); i < x_size; i++) {
			indegree[x[temp][i]]--;
			if (indegree[x[temp][i]] == 0) qu.push(x[temp][i]);
		}
	}
}