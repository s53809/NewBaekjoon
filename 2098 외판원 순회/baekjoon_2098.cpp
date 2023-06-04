#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> x;
vector<vector<int>> dp;
int ansState = 0;

int DFS(int pos, int state) {
	if (x[pos][0] != 0 && state == ansState) { return x[pos][0]; }
	else if (x[pos][0] == 0 && state == ansState) return 1e9;
	if (dp[pos][state] != 0) return dp[pos][state];

	dp[pos][state] = 1e9;
	for (int i = 0; i < N; i++) {
		if (x[pos][i] != 0 && (state & (1 << i)) == 0) {
			dp[pos][state] = min(dp[pos][state], x[pos][i] + DFS(i, state | (1 << i)));
		}
	}
	return dp[pos][state];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N, vector<int>(N));
	dp.resize(N, vector<int>((1 << N) , 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x[i][j];
		}
	}

	ansState = (1 << N) - 1;

	cout << DFS(0, 1);
}