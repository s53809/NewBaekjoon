#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<int> x(100001, -1);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> K;

	queue<int> qu;
	qu.push(N);
	x[N] = 0;
	while (!qu.empty()) {
		int dist = qu.front();
		qu.pop();
		if (dist < 100000 && dist < K && (x[dist + 1] == -1 || x[dist + 1] > x[dist] + 1)) {
			x[dist + 1] = x[dist] + 1;
			qu.push(dist + 1);
		}
		if (dist > 0 && (x[dist - 1] == -1 || x[dist - 1] > x[dist] + 1)) {
			x[dist - 1] = x[dist] + 1;
			qu.push(dist - 1);
		}
		if (dist * 2 <= 100000 && (x[dist * 2] == -1 || x[dist * 2] > x[dist] + 1)) {
			x[dist * 2] = x[dist] + 1;
			qu.push(dist * 2);
		}
	}
	cout << x[K];
}