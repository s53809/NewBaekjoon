#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<pair<int, int>, pair<int, int>>> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i].first.first >> x[i].first.second >> x[i].second.first >> x[i].second.second;
	}

	sort(x.begin(), x.end());
// 	cout << '\n';
// 	for (int i = 0; i < N; i++) {
// 		cout << x[i].first.first << ' ' << x[i].first.second << ' ' << x[i].second.first << ' ' << x[i].second.second << '\n';
// 	}
// 	cout << '\n';
	pair<int, int> maxDay = make_pair(3, 1);
	int pos = 0;
	int ans = 0;

	while (maxDay < make_pair(12, 1)) {
		//cout << maxDay.first << ' ' << maxDay.second << '\n';
		pair<int, int> nextMaxDay = make_pair(0, 0);

		bool isBulganung = true;

		while (pos < N && maxDay >= x[pos].first) {
			isBulganung = false;
			pair<int, int> dist = x[pos++].second;
			if (nextMaxDay < dist) {
				nextMaxDay = dist;
			}
		}
		if (isBulganung) { cout << 0; return 0; }
		ans++;
		maxDay = nextMaxDay;
	}

	cout << ans;
}