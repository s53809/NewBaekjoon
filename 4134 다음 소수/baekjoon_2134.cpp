#include <iostream>
#include <cmath>
#define lld long long int
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		lld N;
		cin >> N;
		if (N == 0 || N == 1) {
			cout << 2 << '\n';
			continue;
		}
		while (true) {
			bool isSosu = true;
			for (lld i = 2; i <= sqrt(N); i++) {
				if (N % i == 0) {
					isSosu = false;
					break;
				}
			}
			if (!isSosu) {
				N++;
			}
			else {
				cout << N << '\n';
				break;
			}
		}
	}
}