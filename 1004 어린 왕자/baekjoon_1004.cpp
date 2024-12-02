#include <iostream>
#include <cmath>
using namespace std;

double getDistance(int x1, int y1, int x2, int y2) {
	double diffX = x1 - x2;
	double diffY = y1 - y2;

	return sqrt((diffX * diffX) + (diffY * diffY));
}

bool isInCircle(int x, int y, int cx, int cy, int r) {
	if (getDistance(x, y, cx, cy) <= r) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int N;
		cin >> N;
		int ans = 0;
		while (N--) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			if (isInCircle(x1, y1, cx, cy, r) && isInCircle(x2, y2, cx, cy, r)) continue;
			if (isInCircle(x1, y1, cx, cy, r)) ans++;
			if (isInCircle(x2, y2, cx, cy, r)) ans++;
		}
		cout << ans << '\n';
	}
}