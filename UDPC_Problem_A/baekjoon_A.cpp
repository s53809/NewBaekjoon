#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	int dScore = 0, pScore = 0;
	bool isDone = false;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		if (isDone) continue;
		if (c == 'D') {
			dScore++;
		}
		else {
			pScore++;
		}
		if (abs(dScore - pScore) >= 2) {
			isDone = true;
		}
	}
	cout << dScore << ":" << pScore;
}