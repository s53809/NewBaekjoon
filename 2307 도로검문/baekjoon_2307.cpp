#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> arr;
vector<int> visited;
vector<int> path;
vector<pair<pair<int, int>, int>> inputData;

void daikstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int dir = pq.top().second;
		pq.pop();

		if (visited[dir] != 0 && visited[dir] < cost) continue;

		for (int i = 1; i <= N; i++) {
			if (arr[dir][i] == 0) continue;
			int dist = cost + arr[dir][i];

			if (visited[i] == 0 || dist < visited[i]) {
				visited[i] = dist;
				pq.push({ -dist, i });
			}
		}
	}
}

void daikstra_start() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int dir = pq.top().second;
		pq.pop();

		if (visited[dir] != 0 && visited[dir] < cost) continue;

		for (int i = 1; i <= N; i++) {
			if (arr[dir][i] == 0) continue;
			int dist = cost + arr[dir][i];

			if (visited[i] == 0 || dist < visited[i]) {
				visited[i] = dist;
				path[i] = dir;
				pq.push({ -dist, i });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	arr.resize(N + 1, vector<int>(N + 1, 0));
	visited.resize(N + 1, 0);
	inputData.resize(M);
	path.resize(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> inputData[i].first.first >> inputData[i].first.second >> inputData[i].second;
		arr[inputData[i].first.first][inputData[i].first.second] = inputData[i].second;
		arr[inputData[i].first.second][inputData[i].first.first] = inputData[i].second;
	}

	daikstra_start();
	int ans = 0;
	int originLength = visited[N];
	fill(visited.begin(), visited.end(), 0);

	int index = N;
	while (path[index] != 1) {
		visited[index] = 1;
		index = path[index];
	}
	visited[index] = 1;

	for (int i = 0; i < M; i++) {
		if (visited[inputData[i].first.first] != 1) inputData[i].first.first = -1;
		if (visited[inputData[i].first.second] != 1) inputData[i].first.first = -1;
	}

	for (int i = 0; i < M; i++) {
		if (inputData[i].first.first == -1) continue;
		arr[inputData[i].first.first][inputData[i].first.second] = 0;
		arr[inputData[i].first.second][inputData[i].first.first] = 0;
		fill(visited.begin(), visited.end(), 0);
		daikstra();
		if (visited[N] == 0) { ans = -1; break; }
		ans = max(ans, visited[N] - originLength);
		arr[inputData[i].first.first][inputData[i].first.second] = inputData[i].second;
		arr[inputData[i].first.second][inputData[i].first.first] = inputData[i].second;
	}

	cout << ans;
}