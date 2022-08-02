#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<pair<int, bool>> x;
		queue<pair<int, bool>> qu;
		x.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> x[i].first;
			if (i != M) x[i].second = false;
			else x[i].second = true;
			qu.push(make_pair(x[i].first, x[i].second));
		}
		int index = 0;
		while (true) {
			index++;
			int high = 0;
			for (int i = 0, qu_size = qu.size(); i < qu_size; i++) {
				if (high < qu.front().first) {
					high = qu.front().first;
				}
				pair<int, bool> temp = qu.front();
				qu.pop();
				qu.push(temp);
			}
			bool isAns = false;
			for (int i = 0, qu_size = qu.size(); i < qu_size; i++) {
				if (qu.front().first == high) {
					if (qu.front().second) {
						isAns = true;
					}
					qu.pop();
					break;
				}
				else {
					pair<int, bool> temp = qu.front();
					qu.pop();
					qu.push(temp);
				}
			}
			if (isAns) {
				break;
			}
		}

		cout << index << '\n';
	}
}