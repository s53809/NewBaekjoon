#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << 10000 + (a * 1000);
	}
	else if (a == b) {
		cout << 1000 + (a * 100);
	}
	else if (b == c) {
		cout << 1000 + (b * 100);
	}
	else if (a == c) {
		cout << 1000 + (a * 100);
	}
	else {
		int top = 0;
		top = max(a, b);
		top = max(top, c);
		cout << 100 * top;
	}
}