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

int BFS(int xPos, int yPos) {
	queue<pair<int, int>> qu;
	qu.push({ xPos, yPos });
	visited[yPos][xPos] = 0;
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dir_x = temp.first + d_x[i];
			int dir_y = temp.second + d_y[i];

			if (0 <= dir_x && dir_x < M && 0 <= dir_y && dir_y < N) {
				if (visited[dir_y][dir_x] != -1 || x[dir_y][dir_x] == 1) continue;
				visited[dir_y][dir_x] = visited[temp.second][temp.first] + 1;
				if (x[dir_y][dir_x] == 3) return visited[dir_y][dir_x];
				qu.push({ dir_x, dir_y });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N, vector<int>(M));
	visited.resize(N, vector<int>(M, -1));

	int strXPos = 0, strYPos = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '2') { strXPos = j; strYPos = i; }
			else if (str[j] - '0' >= 3) str[j] = '3';
			x[i][j] = str[j] - '0';
		}
	}

	int ans = BFS(strXPos, strYPos);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	if (ans == -1) cout << "NIE";
	else {
		cout << "TAK\n" << ans;
	}
	
}