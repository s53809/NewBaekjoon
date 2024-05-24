#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> x(1000001);
vector<bool> visited(1000001);
vector<vector<int>> dp(1000001, vector<int>(2, -1));

int Func(int num, int flag) {
	if (dp[num][flag] != -1) return dp[num][flag];
	visited[num] = true;
	dp[num][flag] = flag;
	if (flag == 0) {
		for (int i = 0, x_size = x[num].size(); i < x_size; i++) {
			if (visited[x[num][i]]) continue;
			dp[num][flag] += Func(x[num][i], 1);
		}
	}
	if (flag == 1) {
		for (int i = 0, x_size = x[num].size(); i < x_size; i++) {
			if (visited[x[num][i]]) continue;
			dp[num][flag] += min(Func(x[num][i], 0), Func(x[num][i], 1));
		}
	}
	visited[num] = false;
	return dp[num][flag];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		x[a].push_back(b);
		x[b].push_back(a);
	}

	int ans = Func(1, 0);
	fill(visited.begin(), visited.end(), false);
	ans = min(ans, Func(1, 1));
	cout << ans;
}