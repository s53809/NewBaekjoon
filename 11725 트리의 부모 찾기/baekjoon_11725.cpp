#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> x;
vector<bool> visited;
vector<int> ans;

void DFS(int pos) {
	visited[pos] = true;
	for (int i = 0, x_size = x[pos].size(); i < x_size; i++) {
		if (!visited[x[pos][i]]) {
			ans[x[pos][i]] = pos;
			DFS(x[pos][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N + 1);
	visited.resize(N + 1, false);
	ans.resize(N + 1, -1);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		x[a].push_back(b);
		x[b].push_back(a);
	}

	DFS(1);

	for (int i = 2; i <= N; i++) {
		cout << ans[i] << '\n';
	}
}