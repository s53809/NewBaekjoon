#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d_x[] = { 0,0,-1,1 };
int d_y[] = { 1,-1,0,0 };

int canTam[6][2] = {
	{0,3},
	{0,2},
	{1,3},
	{1,2},
	{0,1},
	{2,3}
};

int posi[4][3] = {
	{2,3,4},
	{0,1,4},
	{0,2,5},
	{1,3,5}
};

int zido[51][51];
int visited[51][51];
int N, K;
bool isNotGyoChae = true;

void print() {
	cout << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}

void DFS(int posX, int posY, bool isChanged) {
	if (posX == N && posY == N - 1 && isChanged) {
		visited[posY][posX] = -1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int dir_x = d_x[i] + posX;
		int dir_y = d_y[i] + posY;

		bool notChange = false;

		for (int j = 0; j < 2; j++) {
			if (canTam[zido[posY][posX]][j] == i) { notChange = true; break; }
		}

		if (!(dir_y == N - 1 && dir_x == N) && !(0 <= dir_x && dir_x < N && 0 <= dir_y && dir_y < N)) continue;

		for (int j = 0; j < 3; j++) {
			if (visited[dir_y][dir_x] < visited[posY][posX] + 1 && visited[dir_y][dir_x] != -1) continue;
			if (zido[dir_y][dir_x] == posi[i][j] || (dir_y == N - 1 && dir_x == N)) {
				if (!notChange && isChanged) {
					visited[dir_y][dir_x] = visited[posY][posX] + 1;
					DFS(dir_x, dir_y, false);
				}
				else if (notChange) {
					visited[dir_y][dir_x] = visited[posY][posX] + 1;
					DFS(dir_x, dir_y, isChanged);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> zido[i][j];
			visited[i][j] = -1;
		}
	}
	visited[N - 1][N] = -1;
	visited[0][0] = 1;

	if ((zido[0][0] == 5 || zido[0][0] == 3 || zido[0][0] == 1) && K == 1) {
		DFS(0, 0, true);
	}
	else if (K == 0) {
		cout << -1;
		return 0;
	}
	else if (K == 1) {
		DFS(0, 0, false);
	}
	else {
		cout << -1;
		return 0;
	}

	//print();

	if (visited[N - 1][N] == -1) { cout << -1; }
	else { cout << visited[N - 1][N] - 1; }
}