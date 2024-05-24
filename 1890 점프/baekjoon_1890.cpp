#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int lld;
using namespace std;

int N;
vector<vector<int>> arr;
vector<vector<lld>> dp;
vector<vector<bool>> visited;

int d_x[2] = { 1, 0 };
int d_y[2] = { 0,1 };

lld DFS(int x, int y) {
	if (x == N - 1 && y == N - 1) return 1;
	if (arr[y][x] == 0) return 0;

	if (dp[y][x] != -1 || visited[y][x]) return dp[y][x];
	visited[y][x] = true;

	dp[y][x] = 0;
	for (int i = 0; i < 2; i++) {
		int dir_x = (d_x[i] * arr[y][x]) + x;
		int dir_y = (d_y[i] * arr[y][x]) + y;

		if (0 <= dir_x && dir_x < N && 0 <= dir_y && dir_y < N) {
			dp[y][x] += DFS(dir_x, dir_y);
		}
	}
	return dp[y][x];
}



int main() {
	cin >> N;
	arr.resize(N, vector<int>(N, 0));
	dp.resize(N, vector<lld>(N, -1));
	visited.resize(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	cout << DFS(0, 0);
}