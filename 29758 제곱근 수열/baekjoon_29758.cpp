#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> dp(70001, vector<int>(6, -1));

int Func(int N, int L) {
	if (L == 1 && N == 1) { return 1; }
	if (L == 1 || N == 1) return 0;
	if (dp[N][L] != -1) return dp[N][L];
	int num = (int)sqrt(N);
	if ((num * num) == N) num--;
	dp[N][L] = 0;
	for (int i = num; i >= 1; i--) {
		dp[N][L] += Func(i, L - 1);
	}
	return dp[N][L];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	
	int T;
	cin >> T;
	while (T--) {
		int N, L;
		cin >> N >> L;
		cout << (L >= 6 ? 0 : Func(N, L)) << '\n';
	}
}