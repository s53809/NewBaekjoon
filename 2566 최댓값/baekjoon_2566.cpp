#include <iostream>
using namespace std;

int main() {
	int x = 0, y = 0;
	int maxValue = -1;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int N;
			cin >> N;
			if (maxValue < N) {
				maxValue = N;
				x = j;
				y = i;
			}
		}
	}

	cout << maxValue << '\n' << y << ' ' << x;
}