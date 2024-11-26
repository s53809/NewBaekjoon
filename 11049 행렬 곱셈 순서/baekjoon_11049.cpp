#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> x;
vector<vector<int>> dp;

int DP(int s, int e) { //s부터 e까지 곱했을 때 최솟값
	if (dp[s][e] != -1) return dp[s][e];
	if (s + 1 == e) return x[s].first * x[s].second * x[e].second;
	if (s == e) return 0;

	dp[s][e] = 2e9;
	for (int i = s; i < e; i++) {
		dp[s][e] = min(dp[s][e], DP(s, i) + DP(i + 1, e) + (x[s].first * x[i].second * x[e].second));
	}
	return dp[s][e];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N);
	dp.resize(N, vector<int>(N, -1));
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}
	cout << DP(0, N - 1);
}