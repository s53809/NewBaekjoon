#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, C, first;
	cin >> N >> M >> C >> first;

	if (N != C) {
		if ((N * first + M) <= (C * first) && N < C) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else cout << ((N * first + M) <= (C * first)) ? 1 : 0;
}