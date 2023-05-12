#include <iostream>
#include <algorithm>
using namespace std;

int price[3][1001];

int N;
int dp[3][1001];

int solve(int num, int color) {
	if (num == N) return 0;
	int& ret = dp[color][num];
	if (ret == 2e9) return ret;
	for (int i = 0; i < 3; i++) {
		if (i == color) continue;
		ret = min(ret, solve(num + 1, i) + dp[color][num]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> price[j][i];
		}
	}
	
	fill(dp, dp + 1001, 2e9);
}