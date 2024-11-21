#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string A, B;
vector<vector<int>> dp;
int ans = 0;

int LCS(int i, int j) {
	if (i == 0 || j == 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	LCS(i - 1, j);
	LCS(i, j - 1);
	dp[i][j] = 0;
	if (A[i - 1] == B[j - 1]) dp[i][j] = max(dp[i - 1][j - 1] + 1, 1);
	ans = max(ans, dp[i][j]);
	return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> A >> B;
	dp.resize(A.size() + 1, vector<int>(B.size() + 1, -1));

	LCS(A.size(), B.size());
	cout << ans;
}