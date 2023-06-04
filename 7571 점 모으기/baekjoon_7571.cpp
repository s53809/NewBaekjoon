#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	vector<int> x;
	vector<int> y;
	cin >> N >> M;
	x.resize(M);
	y.resize(M);

	for (int i = 0; i < M; i++) {
		cin >> x[i] >> y[i];
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int ans = 0;
	for (int i = 0; i < M; i++) {
		ans += abs(x[i] - x[(M / 2)]);
		ans += abs(y[i] - y[(M / 2)]);
	}
	cout << ans;
}