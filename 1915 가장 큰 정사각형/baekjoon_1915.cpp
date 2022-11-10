#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<string> x(N);
	vector<vector<int>> arr;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		arr[i].resize(M);
		cin >> x[i];
		for (int j = 0; j < M; j++) {
			arr[i][j] = x[i][j] - '0';
		}
	}

	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((i == 0 || j == 0) && arr[i][j] != 0) {
				if (max < 1) {
					max = 1;
				}
			}
			else if (arr[i][j] != 0) {
				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
			}
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	cout << max * max;
}