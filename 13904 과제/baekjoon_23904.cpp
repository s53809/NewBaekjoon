#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> x(N);
	int maxDay = 0;

	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
		maxDay = max(maxDay, x[i].first);
	}

	sort(x.begin(), x.end(), 
		[](pair<int, int> a, pair<int, int> b) { return (a.second == b.second) ? a.first > b.first : a.second > b.second; });

	int ans = 0;

	for (int i = maxDay; i > 0; i--) {
		for (int j = 0; j < N; j++) {
			if (x[j].second != 0 && i <= x[j].first) {
				ans += x[j].second;
				x[j].second = 0;
				break;
			}
		}
	}

	cout << ans;
}