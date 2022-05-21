#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<vector<int>> x;
int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };
queue<pair<int, int>> qu;

bool BFS() {
	int qu_size = qu.size();
	bool isAllGone = true;
	for (int u = 0; u < qu_size; u++) {
		int xPos = qu.front().first;
		int yPos = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = d_x[i] + xPos;
			int dir_y = d_y[i] + yPos;
			if (dir_x >= 0 && dir_x < M && dir_y >= 0 && dir_y < N) {
				if (x[dir_y][dir_x] == 0) {
					x[dir_y][dir_x] = 1;
					qu.push(make_pair(dir_x, dir_y));
					isAllGone = false;
				}
			}
		}
	}
	return isAllGone;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		x[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> x[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (x[i][j] == 1) {
				qu.push(make_pair(j, i));
			}
		}
	}
	bool isDone = false;
	int ans = 0;
	while (!isDone) {
		isDone = BFS();
		ans++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (x[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << --ans;
}