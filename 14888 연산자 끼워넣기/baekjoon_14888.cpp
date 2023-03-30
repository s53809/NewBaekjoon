#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int operators[] = { 0,0,0,0 }; // +, -, x, /
int N;
vector<int> x;
int low = 2e9, high = -2e9;

void yonsan(int num, int curNum) {
	if (num == N) {
		low = min(low, curNum);
		high = max(high, curNum);
	}
	else {
		if (operators[0] > 0) {
			operators[0]--;
			yonsan(num + 1, curNum + x[num]);
			operators[0]++;
		}
		if (operators[1] > 0) {
			operators[1]--;
			yonsan(num + 1, curNum - x[num]);
			operators[1]++;
		}
		if (operators[2] > 0) {
			operators[2]--;
			yonsan(num + 1, curNum * x[num]);
			operators[2]++;
		}
		if (operators[3] > 0) {
			operators[3]--;
			yonsan(num + 1, curNum / x[num]);
			operators[3]++;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	yonsan(1, x[0]);

	cout << high << '\n' << low;
}