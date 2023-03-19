#include <iostream>
#define lld long long int
using namespace std;

int uClid(lld a, lld b) {
	if (!b) return a;
	else return uClid(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	lld a, b;
	cin >> a >> b;
	cout << (a * b) / uClid(a, b);
}