#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ii pair<int, int>
using namespace std;

int N;
vector<vector<int>> x;
vector<vector<int>> visited;

int d_x[] = { 0,-1,1,0 };
int d_y[] = { -1,0,0,1 };

ii sharkPos = { -1,-1 };
int sharkState = 2;
int ateFish = 0;

/*
아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.
따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
*/

int getLength(ii startPos, ii endPos) {
	return abs(endPos.first - startPos.first) + abs(endPos.second - startPos.second);
}

ii BFS() {
	queue<ii> qu;
	vector<ii> sharkList;
	int sharkDis = -1;
	qu.push(sharkPos);
	visited[sharkPos.second][sharkPos.first] = -1;
	while (!qu.empty()) {
		ii temp = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = temp.first + d_x[i];
			int dir_y = temp.second + d_y[i];
			if (dir_x < 0 || dir_x >= N || dir_y < 0 || dir_y >= N) continue;
			if (visited[dir_y][dir_x] != 0) continue; // 이미 방문헀는가
			if (x[dir_y][dir_x] > sharkState) continue; //지나갈 수 없음 조건
			if (x[dir_y][dir_x] == 0 || x[dir_y][dir_x] == sharkState) {
				if (visited[temp.second][temp.first] == -1) visited[dir_y][dir_x] = 1;
				else visited[dir_y][dir_x] = visited[temp.second][temp.first] + 1;
				qu.push({ dir_x,dir_y });
			}
			else if (x[dir_y][dir_x] < sharkState 
				&& (sharkDis == -1 || sharkDis >= visited[temp.second][temp.first] + 1)) {
				if (visited[temp.second][temp.first] == -1) sharkDis = 1;
				else sharkDis = visited[temp.second][temp.first] + 1;
				//BFS 특성상 가장 거리가 가까운 노드가 먼저 도달할 수 밖에 없음
				sharkList.push_back({ dir_y,dir_x });
				if (visited[temp.second][temp.first] == -1) visited[dir_y][dir_x] = 1;
				else visited[dir_y][dir_x] = visited[temp.second][temp.first] + 1;
			}
		}
	}
	if(sharkList.empty()) return { -1,-1 };
	sort(sharkList.begin(), sharkList.end());
	x[sharkPos.second][sharkPos.first] = 0;
	sharkPos = { sharkList[0].second, sharkList[0].first };
	x[sharkList[0].first][sharkList[0].second] = 9;
	ateFish++;
	if (ateFish >= sharkState && sharkState <= 6) {
		ateFish = 0; 
		sharkState++;
	}
	return { sharkList[0].second, sharkList[0].first };
}

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << x[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N, vector<int>(N));
	visited.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x[i][j];
			if (x[i][j] == 9) sharkPos = { j,i };
		}
	}

	int time = 0;
	while (true) {
		for (int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].end(), false);
		ii temp = sharkPos;
		//cout << "\n현재 shark state" << sharkState << '\n';
		ii result = BFS();
		//Print();
		if (result.first == -1 && result.second == -1) break;
		time += visited[result.second][result.first];
		//cout << "결과 : " << time << '\n';
	}
	cout << time;
}