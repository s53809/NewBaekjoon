#include <iostream>
#include <cmath>
using namespace std;

int x[246913] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	x[0] = 0;
	x[1] = 0;

	for (int i = 1; i < 246913; i++) {
		x[i] = 1;
	}

	for (int i = 2; i <= sqrt(246913); i++) {
		if (x[i] == 0) continue;
		for (int j = i * i; j <= 246913; j += i) {
			x[j] = 0;
		}
	}

	for (int i = 1; i < 246913; i++) {
		x[i] += x[i - 1];
	}

	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		cout << x[N * 2] - x[N] << '\n';
	}
}