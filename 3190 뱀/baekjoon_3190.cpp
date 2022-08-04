#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

// +: 오른쪽 회전 | -: 왼쪽 회전
// 0: 빈 공간 | 1: 뱀 | 2: 사과
int d_y[] = { 0,1,0,-1 };
int d_x[] = { 1,0,-1,0 };

int N, K, L;
vector<vector<int>> x;
vector<pair<int, char>> info;

int Vec = 0; // 방향 정보
int sec = 0;
int infoNum = 0;
int snake_length = 1;
deque<pair<int,int>> snake;

void print_map() {
	for (int i = 0, x_size = x.size(); i < x_size; i++) {
		for (int j = 0, x__size = x[i].size(); j < x__size; j++) {
			cout << x[i][j];
		}
		cout << '\n';
	}

	cout << '\n';
}

bool moveSnake() {
	pair<int, int> snake_tail = snake.back();

	int dir_x = snake.front().first + d_x[Vec];
	int dir_y = snake.front().second + d_y[Vec];

	//cout << "(" << dir_x << ", " << dir_y << ")\n";

	snake.pop_back();

	if (dir_x < 0 || dir_x >= N || dir_y < 0 || dir_y >= N) { // 뱀의 머리가 벽에 부딫혔을 때
		//cout << "뱀이 머리에 부딫혔다\n";
		return true;
	}
	else if (x[dir_y][dir_x] == 2) { // 뱀이 사과를 먹었을 때
		//cout << "뱀이 사과를 먹었다\n";
		snake.push_back(make_pair(snake_tail.first, snake_tail.second));
		x[snake_tail.second][snake_tail.first] = 1;
	}
	else if (x[dir_y][dir_x] == 1) { // 뱀이 자기 자신에게 닿았을 때
		//cout << "뱀이 자기 자신과 닿았다\n";
		return true;
	}
	else {
		x[snake_tail.second][snake_tail.first] = 0;
	}


	snake.push_front(make_pair(dir_x, dir_y));
	pair<int, int> snake_head = snake.front();

	x[snake_head.second][snake_head.first] = 1;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	x.resize(N);
	for (int i = 0; i < N; i++) {
		x[i].resize(N);
		for (int j = 0; j < N; j++) {
			x[i][j] = 0;
		}
	}

	x[0][0] = 1;

	for (int i = 0; i < K; i++) {
		int xPos, yPos;
		cin >> xPos >> yPos;
		x[xPos - 1][yPos - 1] = 2;
	}

	cin >> L;

	info.resize(L);

	for (int i = 0; i < L; i++) {
		cin >> info[i].first >> info[i].second;
	}

	snake.push_front(make_pair(0, 0));

	//print_map();

	while (true) {
		sec++;
		bool isDead = moveSnake();
		//cout << sec << "번째 날입니다. " << Vec << "\n";
		print_map();
		if (isDead) {
			break;
		}
		if (infoNum < info.size() && sec == info[infoNum].first) {
			if (info[infoNum].second == 'D') {
				Vec = (Vec + 1) % 4;
			}
			else {
				Vec = (Vec - 1) % 4;
				if (Vec == -1) {
					Vec = 3;
				}
			}
			infoNum++;
		}

	}
	cout << sec;
}