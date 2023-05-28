#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	vector<vector<int>> x(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> hap(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x[i][j];
			hap[i][j] = x[i][j] + (hap[i - 1][j] + hap[i][j - 1] - hap[i - 1][j - 1]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << hap[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << hap[y2][x2] - (hap[y2][x1 - 1] + hap[y1 - 1][x2] - hap[y1 - 1][x1 - 1]) << '\n';
	}
}