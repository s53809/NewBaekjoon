#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };
vector<string> x;
vector<vector<bool>> visited;
vector<pair<int, int>> baekjo;
queue<pair<int, int>> nokMul;
queue<pair<int, int>> qu;

int N, M;
bool flag = false;

void BFS() {
	int nokMul_size = nokMul.size();
	while (nokMul_size--) {
		pair<int, int> dist = nokMul.front();
		nokMul.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = dist.second + d_x[i];
			int dir_y = dist.first + d_y[i];
			if (dir_x < 0 || dir_x >= M || dir_y < 0 || dir_y >= N) { continue; }
			if (x[dir_y][dir_x] == 'X') {
				x[dir_y][dir_x] = '.';
				nokMul.push(make_pair(dir_y, dir_x));
			}
		}
	}
}

void find_baekjo() {
	queue<pair<int, int>> nextQu;
	while (!qu.empty()) {
		pair<int, int> dist = qu.front();
		qu.pop();
		if (dist.second == baekjo[1].second && dist.first == baekjo[1].first) {
			flag = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int dir_x = dist.second + d_x[i];
			int dir_y = dist.first + d_y[i];
			if (dir_x < 0 || dir_x >= M || dir_y < 0 || dir_y >= N || visited[dir_y][dir_x]) { continue; }
			visited[dir_y][dir_x] = true;
			if (x[dir_y][dir_x] == 'X') {
				nextQu.push(make_pair(dir_y, dir_x));
				continue;
			}
			qu.push(make_pair(dir_y, dir_x));
		}
	}
	qu = nextQu;
}

void printBaekjo() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << x[i][j];
		}
		cout << '\n';
	}
	cout << "===================\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	x.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; i++) {
		visited[i].resize(M);
		fill(visited[i].begin(), visited[i].end(), false);
		cin >> x[i];
		for (int j = 0; j < M; j++) {
			if (x[i][j] == 'L') {
				baekjo.push_back(make_pair(i, j));
				nokMul.push(make_pair(i, j));
			}
			if (x[i][j] == '.') {
				nokMul.push(make_pair(i, j));
			}
		}
	}
	int count = 0;
	qu.push(make_pair(baekjo[0].first, baekjo[0].second));
	visited[baekjo[0].first][baekjo[0].second] = true;
	while (true) {
		find_baekjo();
		BFS();
		//printBaekjo();
		if (flag) {
			break;
		}
		count++;
	}
	cout << count;
}