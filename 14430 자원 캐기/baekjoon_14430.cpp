#include <iostream>
using namespace std;

int x[301][301] = { 0 };
int dp[301][301] = { 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> x[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = x[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[N][M];
}