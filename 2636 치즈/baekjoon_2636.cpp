#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> x;
vector<vector<bool>> visited;

int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };

int CheckIsEmpty() {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (x[i][j] == 2) { if (cnt != -1) cnt++; x[i][j] = 0; }
			if (x[i][j] != 0) cnt = -1;
		}
	}
	return cnt;
}

void BFS() {
	queue<pair<int, int>> qu;
	fill(visited.begin(), visited.end(), vector<bool>(M, false));
	qu.push({ 0,0 });
	visited[0][0] = true;
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dir_x = temp.first + d_x[i];
			int dir_y = temp.second + d_y[i];
			if ((0 <= dir_x && dir_x < M) && (0 <= dir_y && dir_y < N)) {
				if (visited[dir_y][dir_x]) continue;
				visited[dir_y][dir_x] = true;
				if (x[dir_y][dir_x] == 1) x[dir_y][dir_x] = 2;
				else qu.push({ dir_x, dir_y });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	x.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M, false));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x[i][j];
		}
	}
	int hour = 0;

	while (true) {
		int cnt = CheckIsEmpty();
		if (cnt != -1) { cout << hour << '\n' << cnt << '\n'; return 0; }
		BFS();
		hour++;
	}
}