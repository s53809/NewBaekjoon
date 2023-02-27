#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int count = 0;

	while (true) {
		count++;
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) {
			break;
		}
		int ans = (V / P) * L;
		if ((V % P) < L) ans += V % P;
		else ans += L;
		cout << "Case " << count << ": " << ans << '\n';
	}
}