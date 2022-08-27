#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int x[101][101];
long long cnt[101][101] = { 0 };
int N;

int d_x[] = { 0,1 };
int d_y[] = { 1,0 };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cnt[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) break;
			if (cnt[i][j] >= 1) {
				for (int u = 0; u < 2; u++) {
					int dir_x = j + (d_x[u] * x[i][j]);
					int dir_y = i + (d_y[u] * x[i][j]);
					if (dir_x >= 0 && dir_x < N && dir_y >= 0 && dir_y < N) {
						if (dir_y == N - 1 && dir_x == N - 1) {
							//cout << j << ' ' << i << ' ' << cnt[i][j] << '\n';
						}
						cnt[dir_y][dir_x] += cnt[i][j];
					}
				}
			}
		}
	}

// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			cout << cnt[i][j] << ' ';
// 		}
// 		cout << '\n';
// 	}

	cout << cnt[N - 1][N - 1];
}