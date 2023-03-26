#include <iostream>
#include <algorithm>
using namespace std;

int N, M, B;
int height[257];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> B;
	int low = 257;
	int top = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			height[input]++;
			low = min(low, input);
			top = max(top, input);
		}
	}

	int ans = 1e9;
	int floor = -1;
	for (int i = low; i <= top; i++) {
		int block = B;
		int time = 0;
		bool canPyontan = true;
		for (int j = top; j > i; j--) {
			block += height[j] * (j - i);
			time += (height[j] * (j - i)) * 2;
		}
		for (int j = low; j < i; j++) {
			block -= height[j] * (i - j);
			if (block < 0) {
				canPyontan = false;
				break;
			}
			time += height[j] * (i - j);
		}
		if (canPyontan) {
			if (ans >= time) {
				ans = time;
				floor = i;
			}
		}
	}

	cout << ans << ' ' << floor;
}