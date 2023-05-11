#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> x;
vector<vector<bool>> visited;
vector<vector<int>> cnt;

int shark_size = 2;

int d_x[] = { 0,-1,0,1 };
int d_y[] = { 1,0,-1,0 };

int BFS(int xPos, int yPos) {
	fill(visited.begin(), visited.end(), vector<bool>(N, false));
	fill(cnt.begin(), cnt.end(), vector<int>(N, 0));

	int step = 0;

	queue<pair<int, int>> qu;
	qu.push({ xPos, yPos });

	while (!qu.empty()) {
		pair<int, int> dist = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = dist.first + d_x[i];
			int dir_y = dist.second + d_y[i];

			if (0 <= dir_x && dir_x < N && 0 <= dir_y && dir_y < N) {
				if (x[dir_y][dir_x] < shark_size) {
					return cnt[yPos][xPos] + 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x[i][j];
		}
	}
}