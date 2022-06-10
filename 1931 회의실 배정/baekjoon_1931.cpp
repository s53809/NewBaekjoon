#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> x;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}

	sort(x.begin(), x.end(), compare);

	int ans = 1;
	int least = x[0].first;

	for (int i = 1; i < N; i++) {
		if (least < x[i].second) {
			continue;
		}
		else {
			ans++;
			least = x[i].first;
		}
	}

	cout << ans;
}