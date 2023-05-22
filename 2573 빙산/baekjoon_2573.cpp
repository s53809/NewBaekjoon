#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> x;
vector<vector<int>> visited;

int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };

void Melt(int xPos, int yPos) {
	for (int i = 0; i < 4; i++) {
		int dir_x = xPos + d_x[i];
		int dir_y = yPos + d_y[i];
		if (0 <= dir_x && dir_x < M && 0 <= dir_y && dir_y < N) {
			if (x[dir_y][dir_x] == 0 && x[yPos][xPos] > 0 && !visited[dir_y][dir_x]) {
				x[yPos][xPos]--;
			}
		}
	}
}

void BFS(int xPos, int yPos) {
	queue<pair<int,int>> qu;
	qu.push({ xPos, yPos });
	visited[yPos][xPos] = true;
	while (!qu.empty()) {
		pair<int, int> dist = qu.front();
		Melt(dist.first, dist.second);
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = dist.first + d_x[i];
			int dir_y = dist.second + d_y[i];
			if (0 <= dir_x && dir_x < M && 0 <= dir_y && dir_y < N) {
				if (!visited[dir_y][dir_x] && x[dir_y][dir_x] != 0) {
					visited[dir_y][dir_x] = true;
					qu.push({ dir_x, dir_y });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<int>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x[i][j];
		}
	}

	int year = 0;
	bool isOne = false;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].end(), false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && x[i][j] != 0) {
					BFS(j, i);
					cnt++;
				}
			}
		}
		if (cnt >= 2) break;
		else if (cnt == 0) {
			isOne = true;
			break;
		}
		year++;
	}
	if (isOne) cout << "0";
	else cout << year;
}