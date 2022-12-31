#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> x;
vector<int> ans;
vector<pair<int, int>> input;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	x.resize(N);
	ans.resize(N);
	input.resize(M);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		ans[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> input[i].first >> input[i].second;
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < M; i++) {
		ans[input[i].first - 1] += input[i].second;
	}
	for (int i = 0; i < N; i++) {
		if (i != 0) ans[i] += ans[x[i] - 1];
		cout << ans[i] << ' ';
	}
}