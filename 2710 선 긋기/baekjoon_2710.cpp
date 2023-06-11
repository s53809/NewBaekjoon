#include <iostream>
#include <vector>
#include <algorithm>
#define lld long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	vector<pair<lld, lld>> x;
	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}

	sort(x.begin(), x.end());

	lld strPos = x[0].first, endPos = x[0].second;

	lld dist = 0;
	for (int i = 1; i < N; i++) {
		if (endPos >= x[i].first) endPos = max(endPos, x[i].second);
		else {
			dist += endPos - strPos;
			strPos = x[i].first;
			endPos = x[i].second;
		}
	}

	dist += endPos - strPos;
	cout << dist;
}