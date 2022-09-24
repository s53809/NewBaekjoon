#include <iostream>
#include <cstdlib>
using namespace std;

int W, H, P, Q, T;

int d_x = 1;
int d_y = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> W >> H >> P >> Q >> T;

	int dir_x = T % (W * 2);
	int dir_y = T % (H * 2);

	int ans_x = dir_x + P;
	int ans_y = dir_y + Q;

	if (ans_x > W) {
		ans_x = W - (ans_x - W);
	}
	if (ans_y > H) {
		ans_y = H - (ans_y - H);
	}
	
	cout << abs(ans_x) << ' ' << abs(ans_y);
}