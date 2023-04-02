#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9
#define lld long long int
using namespace std;

int N, M;
vector<vector<lld>> x;

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << x[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N + 1, vector<lld>(N + 1, INF));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		x[a][b] = 1;
		x[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		x[i][i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (x[j][i] + x[i][k] < x[j][k]) {
					//cout << x[j][i] << ' ' << x[i][k] << ' ' << x[j][k] << '\n';
					x[j][k] = x[j][i] + x[i][k];
				}
			}
		}
	}

	//print();

	int low = 2e9;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int hap = 0;
		for (int j = 1; j <= N; j++) {
			hap += x[i][j];
		}
		if (low > hap) {
			low = hap;
			ans = i;
		}
	}

	cout << ans;
}