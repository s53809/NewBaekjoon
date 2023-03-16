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
	vector<pair<int, int>> copy_x(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i].first;
		x[i].second = i;
	}

	sort(x.begin(), x.end());

	int cnt = 0;
	copy_x[0].first = cnt;
	copy_x[0].second = x[0].second;
	for (int i = 1; i < N; i++) {
		if (x[i - 1].first == x[i].first) {
			copy_x[i].first = cnt;
			copy_x[i].second = x[i].second;
		}
		else {
			copy_x[i].first = ++cnt;
			copy_x[i].second = x[i].second;
		}
	}

	sort(copy_x.begin(), copy_x.end(), [](pair<int, int> a, pair<int, int> b) {return a.second < b.second; });

	for (int i = 0; i < N; i++) {
		cout << copy_x[i].first << ' ';
	}
}