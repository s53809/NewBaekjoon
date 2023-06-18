#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<pair<int, int>> x;
vector<int> dp;

int gizi(int xPos) {
	if (dp[xPos] != -1) return dp[xPos];
	if (xPos == 0) return 0;
	if (xPos == 1) return abs(x[xPos].second * 2);
	dp[xPos] = abs(x[xPos].second * 2) + gizi(xPos - 1);
	int maxYPos = abs(x[xPos].second);
	for (int i = xPos - 1; i >= 1; i--) {
		maxYPos = max(maxYPos, abs(x[i].second));
		dp[xPos] = min(dp[xPos], max(x[xPos].first - x[i].first, maxYPos * 2) + gizi(i - 1));
	}
	return dp[xPos];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N + 1);
	dp.resize(N + 1, -1);
	for (int i = 1; i <= N; i++) {
		cin >> x[i].first >> x[i].second;
	}
	sort(x.begin() + 1, x.end()); 

	cout << gizi(N) << '\n';
}