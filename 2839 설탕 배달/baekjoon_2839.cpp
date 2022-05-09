#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int ans = 0;
	while (true) {
		if (N < 3) break;
		if (N % 5 == 0) {
			ans += N / 5;
			N = 0;
			break;
		}
		N -= 3;
		ans++;
	}
	if (N > 0) cout << "-1";
	else cout << ans;
}