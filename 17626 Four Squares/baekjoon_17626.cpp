#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> dp(50001, 1e9);

int	getSu(int N) {
	if (dp[N] != 1e9) return dp[N];
	for (int i = 1; i * i <= N; i++) {
		dp[N] = min(dp[N], getSu(i * i) + getSu(N - (i * i)));
	}
	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	
	for (int i = 1; i * i <= N; i++) {
		dp[i * i] = 1;
	}

	cout << getSu(N);
}