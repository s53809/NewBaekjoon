#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string A, B;
vector<vector<int>> dp;

int LCS(int i, int j) {
	if (i == 0) return dp[i][j] = j;
	if (j == 0) return dp[i][j] = i;
	if (dp[i][j] != -1) return dp[i][j];

	if (A[i - 1] == B[j - 1]) return dp[i][j] = LCS(i - 1, j - 1);
	else return dp[i][j] = min(LCS(i - 1, j - 1), min(LCS(i - 1, j), LCS(i, j - 1))) + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> A >> B;
	dp.resize(A.size() + 1, vector<int>(B.size() + 1, -1));

	cout << LCS(A.size(), B.size());
}