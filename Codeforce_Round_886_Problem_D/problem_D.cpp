#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> x(N);
		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		int maxLength = 0;
		int curLength = 1;
		for (int i = 1; i < N; i++) {
			if (x[i] - x[i - 1] <= K) {
				curLength++;
			}
			else {
				maxLength = max(maxLength, curLength);
				curLength = 1;
			}
		}
		maxLength = max(maxLength, curLength);
		cout << N - maxLength << '\n';
	}
}