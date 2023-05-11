#include <iostream>
using namespace std;

long long x[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		x[0][i] = 1;
	}
	for (int i = 0; i < M; i++) {
		x[i][0] = 1;
	}

	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			x[i][j] = (x[i - 1][j] + x[i][j - 1] + x[i - 1][j - 1]) % 1000000007;
		}
	}

	cout << x[M - 1][N - 1];
}