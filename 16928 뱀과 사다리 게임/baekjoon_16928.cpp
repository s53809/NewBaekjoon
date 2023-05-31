#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<int> x(101, -1);
vector<int> dist(101, -1);

void BFS() {
	queue<int> qu;
	dist[1] = 0;
	qu.push(1);
	while (!qu.empty()) {
		int temp = qu.front();
		qu.pop();

		for (int i = 1; i <= 6; i++) {
			int dir = temp + i;
			if (dir > 100) continue;
			if (x[dir] != -1) dir = x[dir];
			if (dist[dir] == -1 || dist[dir] > dist[temp] + 1) {
				qu.push(dir);
				dist[dir] = dist[temp] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		x[a] = b;
	}
	for (int j = 0; j < M; j++) {
		int a, b;
		cin >> a >> b;
		x[a] = b;
	}

	BFS();
	cout << dist[100];
}