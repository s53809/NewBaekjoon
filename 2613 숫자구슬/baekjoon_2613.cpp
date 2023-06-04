#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N, M;
vector<int> x;
vector<vector<int>> dp;

int divideViz(int num, int div) {
	if (dp[num][div] != 1e9) { return dp[num][div]; }
	for (int i = 1; i <= num - div; i++) {
		int temp = max(divideViz(num - i, div - 1), dp[num][0] - dp[num - i][0]);
		if (dp[num][div] > temp) {
			dp[num][div] = temp;
		}
		
	}
	return dp[num][div];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N + 1);
	dp.resize(N + 1, vector<int>(M, 1e9));
	for (int i = 1; i <= N; i++) {
		cin >> x[i];
		dp[i][0] = (i != 1) ? x[i] + dp[i - 1][0] : x[i];
	}

	int ans = divideViz(N, M - 1);
	cout << ans << '\n';

	stack<int> st;

	int lastNum = N;
	int lastAns = ans;
	for (int i = M - 2; i >= 0; i--) {
		for (int j = lastNum; j >= 0; j--) {
			if (dp[j][i] <= lastAns) {
				st.push(lastNum - j);
				lastNum = j;
				lastAns = dp[j][i];
				break;
			}
		}
	}

	cout << lastNum << ' ';
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}