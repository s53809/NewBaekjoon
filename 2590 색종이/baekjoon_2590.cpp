#include <iostream>
#include <vector>
using namespace std;

vector<int> papers(6);
int ans = 0;

void zongECalculator(int maxTwo, int maxOne);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 6; i++) {
		cin >> papers[i];
	}

	ans = papers[5]; // 6x6 판
	papers[5] = 0;
	
	for (int i = 0; i < papers[4]; i++) { // 5x5 판
		ans++;
		if (papers[0] >= 11) {
			papers[0] -= 11;
		}
		else {
			papers[0] = 0;
		}
	}

	for (int i = 0; i < papers[3]; i++) { // 4x4 판
		ans++;
		int twoStack = 0;
		if (papers[1] >= 5) {
			papers[1] -= 5;
		}
		else {
			twoStack = 5 - papers[1];
			papers[1] = 0;
		}
		if (twoStack != 0) {
			if (papers[0] >= (twoStack * 4)) {
				papers[0] -= (twoStack * 4);
			}
			else {
				papers[0] = 0;
			}
		}
	}

	while (papers[2] != 0) { // 3x3 판
		int threeStack = 0;
		ans++;
		if (papers[2] >= 4) {
			papers[2] -= 4;
		}
		else {
			threeStack = papers[2];
			papers[2] = 0;
		}

		if (threeStack == 1) {
			zongECalculator(5, 7);
		}
		else if (threeStack == 2) {
			zongECalculator(3, 6);
		}
		else if (threeStack == 3) {
			zongECalculator(1, 5);
		}
	} //(3,4) or (3,1 ),(2,7),(1,7) or (3,2),(2,3),(1,6) or (3,3),(2,1),(1,5)

	while (papers[1] != 0) {
		ans++;
		int oneStack = 0;
		if (papers[1] >= 9) {
			papers[1] -= 9;
		}
		else {
			oneStack = 9 - papers[1];
			papers[1] = 0;
		}
		if (oneStack != 0) {
			if (papers[0] >= oneStack * 4) {
				papers[0] -= (oneStack * 4);
			}
			else {
				papers[0] = 0;
			}
		}
	}
	while (papers[0] != 0) {
		ans++;
		if (papers[0] >= 36) {
			papers[0] -= 36;
		}
		else {
			papers[0] = 0;
		}
	}

	cout << ans;
}

void zongECalculator(int maxTwo, int maxOne) {
	int twoStack = 0;
	if (papers[1] >= maxTwo) {
		papers[1] -= maxTwo;
	}
	else {
		twoStack = maxTwo - papers[1];
		papers[1] = 0;
	}
	if (papers[0] >= maxOne + (twoStack * 4)) {
		papers[0] -= maxOne + (twoStack * 4);
	}
	else {
		papers[0] = 0;
	}
}