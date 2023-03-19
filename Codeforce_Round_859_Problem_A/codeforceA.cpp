#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b == c) {
			cout << "+\n";
		}
		else {
			cout << "-\n";
		}
	}
}