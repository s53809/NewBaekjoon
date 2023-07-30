#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> x;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> inDegree;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N + 1);
	inDegree.resize(N + 1, false);
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		x[a].push_back(b);
		inDegree[b]++;
	}

	for (int i = 1; i <= N; i++) if (!inDegree[i]) pq.push(i);

	while (!pq.empty()) {
		int temp = pq.top(); pq.pop();
		cout << temp << ' ';
		for (int i = 0, size = x[temp].size(); i < size; i++) {
			int next = x[temp][i];
			inDegree[next]--;
			if(!inDegree[next]) pq.push(x[temp][i]);
		}
	}
}