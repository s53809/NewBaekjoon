#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<bool> visited(N + 1, false);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			pq.push({ b,a });
		}

		int cnt = 0;
		while (!pq.empty()) {
			ii temp = pq.top(); pq.pop();

			for (int i = temp.second; i <= temp.first; i++) {
				if (!visited[i]) {
					visited[i] = true;
					cnt++;
					break;
				}
			}
		}
		cout << cnt << '\n';
	}
}