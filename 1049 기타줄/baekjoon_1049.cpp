#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	int package = 2e9;
	int natgae = 2e9;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		package = min(package, a);
		natgae = min(natgae, b);
	}

	int ans = 0;

	while (N != 0) {
		if (N >= 6) {
			ans += min(package, natgae * 6);
			N -= 6;
		}
		else {
			ans += min(package, natgae * N);
			N = 0;
		}
	}

	cout << ans;
}