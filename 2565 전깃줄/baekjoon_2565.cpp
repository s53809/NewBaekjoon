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
	vector<pair<int,int>> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}

	sort(x.begin(), x.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		else {
			return a.second < b.second;
		}
		});

	vector<int> length(N);
	int ans = 0;

	for (int i = 0; i < N; i++) {
		length[i] = 1;
		for (int j = 0; j < i; j++) {
			if (x[i].first > x[j].first) {
				length[i] = max(length[i], length[j] + 1);
				ans = max(length[i], ans);
			}
		}
	}
	cout << N - ans;
}