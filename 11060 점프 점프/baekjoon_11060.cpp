#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int N;
int x[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		dp[i] = 1e9;
	}

	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j <= i + x[i]; j++) {
			if (j >= 1000) break;
			dp[j] = min(dp[i] + 1, dp[j]);
		}
	}

	if (dp[N - 1] >= 1e9) {
		cout << "-1";
	}
	else cout << dp[N - 1];
}