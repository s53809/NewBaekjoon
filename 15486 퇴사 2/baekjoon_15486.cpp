#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int N;
vector<int> T;
vector<int> P;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	T.resize(N);
	P.resize(N);
	dp.resize(N + 1, -1);

	dp[0] = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
		if(i != 0) dp[i] = max(dp[i], dp[i - 1]);
		ans = max(ans, dp[i]);
		if (i + T[i] > N) continue;
		dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
	}
	ans = max(ans, dp[N]);
	cout << ans;
}