#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> x;
vector<int> dp;

int pow2(int x) { return x * x; }

int DP(int index) {
	if (index >= N) return 0;
	if (dp[index] != -1) return dp[index];

	dp[index] = 2e9;
	int hap = 0;
	for (int i = 0; index + i < N; i++) {
		hap += x[index + i] + 1;
		if (hap - 1 > M) break;
		dp[index] = min(dp[index],
			(index + i != N - 1) ? pow2(M - (hap - 1)) + DP(index + i + 1) : 0);
	}
	//cout << "DP[" << index << "]=" << dp[index] << '\n';
	return dp[index];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N);
	dp.resize(N + 1, -1);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	cout << DP(0);
}
/*
DP(N) : N번째 이름을 첫 줄의 이름으로 쓸 때
DP(N) = min(N ~ i - 1 + DP(N+i))
*/