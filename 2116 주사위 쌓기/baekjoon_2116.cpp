#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> x;
int ans = 0;
int ban[3][2] = {
	{0,5},
	{1,3},
	{2,4}
};

void hap(int banNum, int num, int curHap) {
	if (num == N) {
		ans = max(ans, curHap);
		return;
	}

	int maxNum = 0;
	for (int i = 0; i < 6; i++) {
		if (x[num - 1][ban[banNum][0]] != x[num][i] && x[num - 1][ban[banNum][1]] != x[num][i]) {
			maxNum = max(maxNum, x[num][i]);
		}
	}

	hap(banNum, num + 1, curHap + maxNum);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		x[i].resize(6);
		for (int j = 0; j < 6; j++) {
			cin >> x[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		int maxNum = 0;
		for (int j = 0; j < 6; j++) {
			if (ban[i][0] != j && ban[i][1] != j) {
				maxNum = max(maxNum, x[0][j]);
			}
		}
		hap(i, 1, maxNum);
	}

	cout << ans;
}