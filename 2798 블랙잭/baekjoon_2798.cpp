#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	int maxNum = 0;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (x[i] + x[j] + x[k] <= M && x[i] + x[j] + x[k] > maxNum) {
					maxNum = x[i] + x[j] + x[k];
				}
			}
		}
	}

	cout << maxNum;
}