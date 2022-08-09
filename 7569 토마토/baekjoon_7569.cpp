#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, H;
vector<vector<vector<int>>> x;
vector<vector<vector<int>>> day;
int d_z[] = { 0,0,0,0,-1,1 };
int d_y[] = { 0,0,-1,1,0,0 };
int d_x[] = { -1,1,0,0,0,0 };

typedef struct triple {
	int x;
	int y;
	int z;
};

triple make_triple(int x, int y, int z) {
	triple temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	return temp;
}

int BFS() {
	int ans = 0;
	queue<triple> qu;

	bool isAllDone = false;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int u = 0; u < M; u++) {
				if (x[i][j][u] == 1) {
					qu.push(make_triple(u, j, i));
				}
			}
		}
	}
	while (!qu.empty()) {
		triple temp = qu.front();
		qu.pop();
		for (int i = 0; i < 6; i++) {
			int dir_x = temp.x + d_x[i];
			int dir_y = temp.y + d_y[i];
			int dir_z = temp.z + d_z[i];

			if (dir_x >= 0 && dir_x < M && dir_y >= 0 && dir_y < N && dir_z >= 0 && dir_z < H) {
				if (x[dir_z][dir_y][dir_x] == 0) {
					x[dir_z][dir_y][dir_x] = 1;
					day[dir_z][dir_y][dir_x] = day[temp.z][temp.y][temp.x] + 1;
					ans = max(ans, day[dir_z][dir_y][dir_x]);
					qu.push(make_triple(dir_x, dir_y, dir_z));
				}
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	x.resize(H);
	day.resize(H);
	for (int i = 0; i < H; i++) {
		x[i].resize(N);
		day[i].resize(N);
		for (int j = 0; j < N; j++) {
			x[i][j].resize(M);
			day[i][j].resize(M);
			for (int u = 0; u < M; u++) {
				day[i][j][u] = 0;
				cin >> x[i][j][u];
			}
		}
	}

	int ans = BFS();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int u = 0; u < M; u++) {
				if (x[i][j][u] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}

	cout << ans;
}