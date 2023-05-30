#include <iostream>
#include <vector>
#define lld long long int
using namespace std;

lld N;
vector<lld> x;

lld dp(lld N) {
	if (x[N] != -1) return x[N];
	if (N == 1) return 1;
	if (N == 0) return 0;
	return x[N] = dp(N - 1) + dp(N - 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		x[i] = -1; // { -1,-1,-1,-1,-1 }
	}

	cout << dp(N);
}