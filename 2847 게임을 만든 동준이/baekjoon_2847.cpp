#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	int ans = 0;

	for (int i = N - 2; i >= 0; i--) {
		if (x[i] >= x[i + 1]) {
			ans += x[i] - x[i + 1] + 1;
			x[i] -= (x[i] - x[i + 1] + 1);
		}
	}

	cout << ans;
}