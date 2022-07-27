#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;
	for (int i = 0; i < N; i++) {
		int box;
		cin >> box;
		if (box == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				if (!pq.top().second) {
					cout << pq.top().first * -1 << '\n';
				}
				else {
					cout << pq.top().first << '\n';
				}
				pq.pop();
			}
		}
		else if (box > 0) {
			pq.push(make_pair(box, true));
		}
		else {
			box *= -1;
			pq.push(make_pair(box, false));
		}
	}

}