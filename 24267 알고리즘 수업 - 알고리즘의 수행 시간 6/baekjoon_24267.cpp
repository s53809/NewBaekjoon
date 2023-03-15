#include <iostream>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll N;
	cin >> N;

	ll ans = 0;
	for (ll i = 1; i <= N - 2; i++) {
		ans += (i * (i + 1)) / 2;
	}

	cout << ans << '\n' << 3;
}