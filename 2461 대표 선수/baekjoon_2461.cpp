#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> x(N, vector<int>(M, 0));
	vector<int> st(N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		sort(x[i].begin(), x[i].end(), [](int a, int b) { return a > b; });
	}

// 	cout << '\n';
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < M; j++) {
// 			cout << x[i][j] << ' ';
// 		}
// 		cout << '\n';
// 	}
// 	cout << '\n';

	int ans = 2e9;

	while (true) {
		int low = 2e9, high = -1;
		int lowN = -1, highN = -1;
		for (int i = 0; i < N; i++) {
			if (low > x[i][st[i]]) {
				low = x[i][st[i]];
				lowN = i;
			}
			if (high < x[i][st[i]]) {
				high = x[i][st[i]];
				highN = i;
			}
		}
// 		cout << "x[" << lowN << ", " << st[lowN] << "] = " << x[lowN][st[lowN]] << '\n';
// 		cout << "x[" << highN << ", " << st[highN] << "] = " << x[highN][st[highN]] << "\n\n";
		st[highN]++;
		ans = min(ans, high - low);
		if (st[highN] >= M) break;
	}
	cout << ans;
}