#include <iostream>
using namespace std;

long long x[91] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	x[0] = 2;
	x[1] = 3;

	if (N <= 2) {
		cout << 1;
		return 0;
	}
	if (N == 3) {
		cout << 2;
		return 0;
	}
	if (N == 4) {
		cout << 3;
		return 0;
	}

	for (int i = 2; i < N - 2; i++) {
		x[i] = x[i - 2] + x[i - 1];
	}

	cout << x[N - 4] + x[N - 5];
}