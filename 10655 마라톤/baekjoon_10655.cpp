#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int getDistance(pair<int, int> x, pair<int, int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	int ans = 2e9;
	vector<pair<int, int>> x(N);
	vector<int> hap(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
		if (i == 0) hap[i] = 0;
		else hap[i] = hap[i - 1] + getDistance(x[i], x[i - 1]);
	}
	for (int i = 1; i < N - 1; i++) {
		ans = min(ans, hap[i - 1] + getDistance(x[i - 1], x[i + 1]) + (hap[N - 1] - hap[i + 1]));
	}
	cout << ans;
}