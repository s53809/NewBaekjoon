#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int W, H;
int x[51][51];

int d_x[] = { -1,0,1,-1,0,1,-1,0,1 };
int d_y[] = { -1,-1,-1,0,0,0,1,1,1 };

void BFS(int xPos, int yPos) {
	queue<pair<int,int>> qu;
	qu.push({ xPos, yPos });

	while (!qu.empty()) {
		pair<int, int> dist = qu.front();
		qu.pop();
		for (int i = 0; i < 9; i++) {
			int dir_x = dist.first + d_x[i];
			int dir_y = dist.second + d_y[i];
			if (0 <= dir_x && dir_x < W && 0 <= dir_y && dir_y < H) {
				if (x[dir_y][dir_x] == 1) {
					qu.push({ dir_x, dir_y });
					x[dir_y][dir_x] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	while (true) {
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> x[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (x[i][j] == 1) {
					x[i][j] = 0;
					BFS(j, i);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}
}