#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<vector<int>> x;
vector<vector<bool>> visited;

int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };

void BFS(int xPos, int yPos, int water) {
	queue<pair<int,int>> qu;
	qu.push({ xPos, yPos });
	while (!qu.empty()) {
		pair<int, int> dist = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = dist.first + d_x[i];
			int dir_y = dist.second + d_y[i];
			if (0 <= dir_x && dir_x < N && 0 <= dir_y && dir_y < N) {
				if (x[dir_y][dir_x] > water && !visited[dir_y][dir_x]) {
					visited[dir_y][dir_x] = true;
					qu.push({ dir_x,dir_y });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N));

	int maxNum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x[i][j];
			maxNum = max(maxNum, x[i][j]);
		}
	}

	int ans = 0;

	for (int water = 1; water <= maxNum; water++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].end(), false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (x[i][j] > water && !visited[i][j]) {
					BFS(j, i, water);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}