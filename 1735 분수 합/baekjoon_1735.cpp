#include <iostream>
using namespace std;

int uClid(int a, int b) {
	if (!b) return a;
	else return uClid(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a1, b1, a2, b2, ans1, ans2;
	cin >> a1 >> b1 >> a2 >> b2;
	int baeN = (b1 * b2) / uClid(b1, b2);
	a1 *= baeN / b1;
	a2 *= baeN / b2;
	
	ans1 = a1 + a2;
	ans2 = baeN;

	cout << ans1 / uClid(ans1, ans2) << ' ' << ans2 / uClid(ans1, ans2);
}