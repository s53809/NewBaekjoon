#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	while (N != 1) {
		for (int i = 2; i <= N; i++) {
			if (N % i == 0) { cout << i << '\n'; N /= i; break; }
		}
	}
}