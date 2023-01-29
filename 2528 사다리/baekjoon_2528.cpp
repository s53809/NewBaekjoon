#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	int maxTime = 0;

	for (int i = N - 1; i > 0; i--) {
		if (arr[i].second == arr[i - 1].second) {
			continue;
		}
		else {
			int mollu = (M - (arr[i].first + arr[i - 1].first)) / 2;
			if ((M - (arr[i].first + arr[i - 1].first)) % 2 != 0) mollu += 1;
			maxTime = max(maxTime, mollu);
		}
	}

	cout << maxTime;
}