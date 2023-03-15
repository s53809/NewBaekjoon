#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int minValue = -1;
	int hap = 0;

	for (int i = N; i <= M; i++) {
		bool isPrimaryNum = true;
		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) { isPrimaryNum = false; break; }
		}
		if (i != 1 && isPrimaryNum) {
			if (minValue == -1) minValue = i;
			hap += i;
		}
	}
	if (minValue == -1) cout << "-1";
	else cout << hap << '\n' << minValue;
}