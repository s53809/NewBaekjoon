#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> x;
vector<int> bag;
int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	x.resize(N);
	bag.resize(K);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}
	sort(x.begin(), x.end());
	sort(bag.begin(), bag.end());

	int j = 0;
	priority_queue<int> pq;
	long long ans = 0;
	for (int i = 0; i < K; i++) {
		while (j < N && bag[i] >= x[j].first) {
			pq.push(x[j++].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}