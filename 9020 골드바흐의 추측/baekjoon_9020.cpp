#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> primaryNum(N + 1);

		for (int i = 0; i <= N; i++) {
			primaryNum[i] = i;
		}
		primaryNum[0] = 0;
		primaryNum[1] = 0;

		for (int i = 0; i <= sqrt(N); i++) {
			if (primaryNum[i] == 0) continue;
			for (int j = i * i; j <= N; j += i) {
				primaryNum[j] = 0;
			}
		}

		for (int i = N; i >= 0; i--) {
			if (primaryNum[i] == 0) primaryNum.erase(primaryNum.begin() + i);
		}

		pair<int, int> plus = make_pair(-1, -1);

		for (int i = 0, pri_size = primaryNum.size(); i < pri_size; i++) {
			for (int j = 0; j <= i; j++) {
				if (primaryNum[i] + primaryNum[j] == N && (plus == make_pair(-1, -1) || plus.second - plus.first > primaryNum[i] - primaryNum[j])) {
					plus.first = primaryNum[i];
					plus.second = primaryNum[j];
				}
			}
		}

		cout << plus.second << ' ' << plus.first << '\n';
	}
}