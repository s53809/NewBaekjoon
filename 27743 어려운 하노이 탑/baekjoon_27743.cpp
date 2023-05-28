#include <iostream>
#define lld long long int
#define div 1000000007
using namespace std;

lld bigPow(lld x, lld y) {
	lld temp = 1;
	while (y > 0) {
		if (y % 2) temp = (temp * x) % div;
		y /= 2;
		x = (x * x) % div;
	}
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	lld N, M;

	cin >> N >> M;
	//M * 2^(N+1) - 2M - 1
	if (M == 1) cout << (bigPow(2, N) - 1) % div;
	else cout << (2 * M * (bigPow(2, N) - 1) + div - 1) % div;
}