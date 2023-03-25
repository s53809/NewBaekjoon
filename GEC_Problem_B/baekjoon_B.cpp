#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, t;
	cin >> t >> N;
	int height = t;
	for (int i = 0; i < N; i++) {
		if (height % 2 == 0) {
			height = (height / 2) ^ 6;
		}
		else {
			height = (height * 2) ^ 6;
		}
	}
	cout << height;
}