#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x[15][15];
	int hap[15][15];

	for (int i = 0; i < 15; i++) {
		x[0][i] = i;
		if (i != 0) hap[0][i] = hap[0][i - 1] + i;
		else hap[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			x[i][j] = hap[i - 1][j];
			if (j != 1) hap[i][j] = x[i][j] + hap[i][j - 1];
			else hap[i][j] = 1;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << x[N][M] << '\n';
	}
}