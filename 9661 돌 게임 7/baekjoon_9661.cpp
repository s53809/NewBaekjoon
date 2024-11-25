#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int lld;
using namespace std;
/*
vector<int> dp(101, -1);

int StoneGame(lld x) {
	if (dp[x] != -1) return dp[x];
	for (int i = 1; i <= x; i *= 4) {
		if (StoneGame(x - i) == 0) return dp[x] = 1;
	}
	return dp[x] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	StoneGame(100);
	for (int i = 0; i < 100; i++) {
		cout << "dp[" << i << "] = " << dp[i] << '\n';
	}
}*/

int main() {
	lld x;
	cin >> x;
	if (x % 5 == 0 || x % 5 == 2) cout << "CY";
	else cout << "SK";
}