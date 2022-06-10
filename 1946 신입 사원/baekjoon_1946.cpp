#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T-- > 0) {
		int N;
		vector<pair<int, int>> x;

		cin >> N;
		x.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> x[i].first >> x[i].second;
		}

		sort(x.begin(), x.end());

		int FirstLeast = x[0].first, SecondLeast = x[0].second;
		pair<bool, bool> isCorrect;
		bool isDone = false;
		int ans = 1;

		for (int i = 1; i < N; i++) {
			isCorrect = make_pair(false, false);
			isDone = false;
			if (FirstLeast > x[i].first) {
				isCorrect.first = true;
				isDone = true;
			}
			if (SecondLeast > x[i].second) {
				isCorrect.second = true;
				isDone = true;
			}
			if (isDone && isCorrect.first) {
				FirstLeast = x[i].first;
			}
			if (isDone && isCorrect.second) {
				SecondLeast = x[i].second;
			}
			
			if (isDone) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}