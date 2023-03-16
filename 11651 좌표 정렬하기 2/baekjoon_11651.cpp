#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].second >> x[i].first;
	}

	sort(x.begin(), x.end());

	for (int i = 0; i < N; i++) {
		cout << x[i].second << ' ' << x[i].first << '\n';
	}
}