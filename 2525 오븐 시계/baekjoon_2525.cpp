#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	cin >> A >> B;

	int time;
	cin >> time;
	B += time;

	if (B >= 60) {
		A += B / 60;
		B = B % 60;
	}

	if (A >= 24) {
		A -= 24;
	}

	cout << A << ' ' << B;
}