#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[301];
int stair[301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = dp[1] + stair[2];
	dp[3] = max(dp[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + dp[i - 3] + stair[i]);
	}

	cout << dp[N];
}