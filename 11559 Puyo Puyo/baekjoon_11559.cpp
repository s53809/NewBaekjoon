#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> arr;
vector<vector<bool>> visited(12);
int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };
stack<pair<int, int>> erase;
bool isBomb = false;
int ans = 0;

void BFS(int y, int x) {
	char color = arr[y][x];
	queue<pair<int, int>> qu;
	qu.push({ y,x });
	erase.push({ y,x });
	visited[y][x] = true;
	int count = 1;
	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = temp.second + d_x[i];
			int dir_y = temp.first + d_y[i];
			if (dir_x < 0 || dir_x >= 6 || dir_y < 0 || dir_y >= 12) {
				continue;
			}
			if (arr[dir_y][dir_x] == color && !visited[dir_y][dir_x]) {
				qu.push({ dir_y,dir_x });
				erase.push({ dir_y,dir_x });
				visited[dir_y][dir_x] = true;
				count++;
			}
		}
	}
	if (count < 4) {
		while (count--) {
			erase.pop();
		}
	}
	else {
		isBomb = true;
	}
}

void Print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

void Erase() {
	while (!erase.empty()) {
		pair<int, int> temp = erase.top();
		arr[temp.first][temp.second] = '.';
		erase.pop();
	}

	for (int i = 0; i < 6; i++) {
		bool isAllGone = true;
		for (int j = 0; j < 12; j++) {
			if (arr[j][i] != '.') {
				isAllGone = false;
				break;
			}
		}
		if (isAllGone) { continue; }
		while (true) {
			int top = 11;
			for (int j = 11; j >= 0; j--) {
				if (arr[j][i] == '.') { top = j; break; }
			}
			bool isDone = true;
			for (int j = top; j >= 0; j--) {
				if (arr[j][i] != '.') { isDone = false; break; }
			}
			if (isDone) break;
			for (int j = top; j > 0; j--) {
				arr[j][i] = arr[j - 1][i];
			}
			arr[0][i] = '.';
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	arr.resize(12);
	for (int i = 0; i < 12; i++) {
		visited[i].resize(6);
		fill(visited[i].begin(), visited[i].end(), false);
		cin >> arr[i];
	}

	while (true) {
		Print();
		isBomb = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (!visited[i][j] && arr[i][j] != '.') {
					BFS(i, j);
				}
			}
		}
		if (!isBomb) {
			break;
		}
		else {
			ans++;
			Erase();
		}
		for (int i = 0; i < 12; i++) {
			fill(visited[i].begin(), visited[i].end(), false);
		}
	}
	cout << ans;
}