#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	vector<int> adjNode;
	vector<int> prevNode;
};

int N, M;
vector<Node> arr;
vector<bool> visited;
int cnt = 0;

void BFS_adj(int startNode) {
	queue<int> qu;
	qu.push(startNode);
	visited[startNode] = true;
	while (!qu.empty()) {
		int dist = qu.front();
		qu.pop();
		for (int i = 0, arr_size = arr[dist].adjNode.size(); i < arr_size; i++) {
			if (visited[arr[dist].adjNode[i]]) continue;
			qu.push(arr[dist].adjNode[i]);
			visited[arr[dist].adjNode[i]] = true;
			cnt++;
		}
	}
}

void BFS_prev(int startNode) {
	queue<int> qu;
	qu.push(startNode);
	visited[startNode] = true;
	while (!qu.empty()) {
		int dist = qu.front();
		qu.pop();
		for (int i = 0, arr_size = arr[dist].prevNode.size(); i < arr_size; i++) {
			if (visited[arr[dist].prevNode[i]]) continue;
			qu.push(arr[dist].prevNode[i]);
			visited[arr[dist].prevNode[i]] = true;
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	arr.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].adjNode.push_back(b);
		arr[b].prevNode.push_back(a);
	}

	int count = 0;

	for (int i = 1; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);
		cnt = 0;
		BFS_adj(i);
		BFS_prev(i);
		if (cnt == N - 1) { count++; }
	}
	cout << count;
}