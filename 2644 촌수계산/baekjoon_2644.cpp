#include <iostream>
#include <vector>
using namespace std;

int N, M;
int startNode, endNode;
vector<vector<int>> x;
vector<bool> visited;
int ans = 2e9;

void DFS(int num, int cnt) {
	if (num == endNode) ans = min(ans, cnt);
	for (int i = 0, x_size = x[num].size(); i < x_size; i++) {
		if (!visited[x[num][i]]) {
			visited[x[num][i]] = true;
			DFS(x[num][i], cnt + 1);
			visited[x[num][i]] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	cin >> startNode >> endNode;
	cin >> M;

	x.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		x[a].push_back(b);
		x[b].push_back(a);
	}

	DFS(startNode, 0);
	if (ans != 2e9) cout << ans;
	else cout << "-1";
}