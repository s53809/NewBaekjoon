#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> x(501);
vector<bool> visited(501);

bool DFS(int pos, int lastNode) {
	visited[pos] = true;
	for (int i = 0, x_size = x[pos].size(); i < x_size; i++) {
		if (x[pos][i] == lastNode) continue;
		if (visited[x[pos][i]]) return false;
		if (!DFS(x[pos][i], pos)) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int cnt = 0;
	while (true) {
		cnt++;
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i <= N; i++) x[i].clear();
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			x[a].push_back(b);
			x[b].push_back(a);
		}

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) if (DFS(i, 0)) { ans++; }
		}
		cout << "Case " << cnt << ": ";
		if (ans > 1) cout << "A forest of " << ans << " trees.\n";
		else if (ans == 1) cout << "There is one tree.\n";
		else cout << "No trees.\n";
	}
}