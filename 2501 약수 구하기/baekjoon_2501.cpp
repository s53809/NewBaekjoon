#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int cnt = 0;
	bool isCorrect = false;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			if (++cnt >= M) { isCorrect = true; cout << i; break; }
		}
	}
	if (!isCorrect)cout << "0";
}