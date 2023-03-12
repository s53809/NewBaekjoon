#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	bool isReverse = false;
	int endPos = -1;

	for (int i = 0; i < N - 1; i++) {
		int temp = x[i] - 1;
		if (temp <= 0) temp = 10;
		if (!isReverse && x[i + 1] != (x[i] + 1) % N) { isReverse = true; }
		else if (isReverse && x[i + 1] != temp) { endPos = i + 1; break; }
	}

	int firstPush = 0;
	pair<int, int> uniFlip;
	int thirdPush = N - endPos;

	vector<int> rightPush;

	int i = endPos;
	int cnt = 0;
	while (cnt < N) {
		cnt++;
		rightPush.push_back(x[i]);
		i = (i + 1) % N;
	}

	for (int i = N - 1; i > 0; i--) {
		if (x[i - 1] != (x[i] + 1) % N) {
			uniFlip.first = i + 1;
			uniFlip.second = N;
			break;
		}
	}

	vector<int> finalPush;
	for (int i = 0; i < uniFlip.first - 1; i++) {
		finalPush.push_back(rightPush[i]);
	}
	for (int i = N - 1; i >= uniFlip.second; i--) {
		finalPush.push_back(rightPush[i]);
	}
	
	for (int i = 0; i < N; i++) {
		if (finalPush[i] == 1) {
			firstPush = N - i;
			break;
		}
	}

	cout << firstPush << '\n' << uniFlip.first << ' ' << uniFlip.second << '\n' << thirdPush;
}