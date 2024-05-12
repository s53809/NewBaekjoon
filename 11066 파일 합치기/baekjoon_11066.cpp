#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
vector<int> sum;
vector<int> x;

int Func(int s, int e) {
	if (s == e) return 0;
	if (dp[s][e] != -1) return dp[s][e];

	dp[s][e] = 2e9;

	for (int i = s; i < e; i++) {
		dp[s][e] = min(dp[s][e], Func(s, i) + Func(i + 1, e) + sum[e] - sum[s - 1]);
	}
	return dp[s][e];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < dp.size(); i++) dp[i].clear();
		dp.clear();
		sum.clear();
		x.clear();
		int N;
		cin >> N;
		x.resize(N + 1, 0);
		dp.resize(N + 1, vector<int>(N + 1, -1));
		sum.resize(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> x[i];
			sum[i] = x[i] + sum[i - 1];
		}
		cout << Func(1, N) << '\n';
	}
}