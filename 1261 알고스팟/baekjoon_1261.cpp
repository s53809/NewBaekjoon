#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> x;
vector<vector<int>> dist;

int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };

void BFS() {
	queue<pair<int,int>> qu;
	qu.push({ 0,0 });
	dist[0][0] = 0;
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = temp.first + d_x[i];
			int dir_y = temp.second + d_y[i];
			if ((0 <= dir_x && dir_x < N) && (0 <= dir_y && dir_y < M)) {
				if (dist[dir_y][dir_x] != -1 && dist[dir_y][dir_x] <= dist[temp.second][temp.first] + x[dir_y][dir_x]) continue;
				dist[dir_y][dir_x] = dist[temp.second][temp.first] + x[dir_y][dir_x];
				qu.push({ dir_x, dir_y });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(M, vector<int>(N));
	dist.resize(M, vector<int>(N, -1));
	for (int i = 0; i < M; i++) {
		string str = "";
		cin >> str;
		for (int j = 0; j < N; j++) {
			x[i][j] = str[j] - '0';
		}
	}
	BFS();
	cout << dist[M - 1][N - 1];
}