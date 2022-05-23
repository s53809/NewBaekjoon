#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
vector<int> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	x.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	int p1 = 0, p2 = 0;
	int sum = x[p1];
	int ans = 0;

	while (p2 < N) {
		if (sum >= S) {
			if (ans == 0 || ans > p2 - p1 + 1) {
				ans = p2 - p1 + 1;
			}
			sum -= x[p1];
			p1++;
		}
		else {
			p2++;
			if (p2 >= N) {
				break;
			}
			sum += x[p2];
		}
	}

	cout << ans;
}