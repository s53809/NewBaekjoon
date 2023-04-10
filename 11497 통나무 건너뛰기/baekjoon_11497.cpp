#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> x(N);
		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		vector<int> copy_x(N);

		int cnt = 0;
		for (int i = 0, j = N - 1; ; i++, j--) {
			if (i <= N / 2) {
				copy_x[i] = x[cnt++];
			}
			if (j >= (N / 2) + 1) {
				copy_x[j] = x[cnt++];
			}
			if (i > N / 2 && j < (N / 2) + 1) {
				break;
			}
		}

		int diff = 0;
		for (int i = 0; i < N - 1; i++) {
			diff = max(diff, abs(copy_x[i] - copy_x[i + 1]));
		}

		diff = max(copy_x[N - 1] - copy_x[0], diff);

		cout << diff << '\n';

	}
}