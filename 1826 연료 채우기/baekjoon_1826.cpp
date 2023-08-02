#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	int L, P;

	cin >> N;
	vector<pair<int, int>> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}
	cin >> L >> P;

	sort(x.begin(), x.end());

	priority_queue<int> pq;
	int idx = 0;

	int cnt = 0;
	while (P < L) {
		for (; idx < N; idx++) {
			if (x[idx].first > P) break;
			pq.push(x[idx].second);
		}
		if (!pq.empty()) {
			P += pq.top(); pq.pop();
			cnt++;
		}
		else if (idx == N || x[idx].first > P) {
			cnt = -1;
			break;
		}
	}

	cout << cnt;
}