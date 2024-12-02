#include <iostream>
#include <cmath>
using namespace std;

int W, H, X, Y, P;

double getDistance(int x1, int y1, int x2, int y2) {
	double diffX = x1 - x2;
	double diffY = y1 - y2;

	return sqrt((diffX * diffX) + (diffY * diffY));
}

bool isInArea(int x, int y) {
	if ((X <= x && x <= X + W) && (Y <= y && y <= Y + H)) {
		return true;
	}
	if (getDistance(x, y, X, Y + (H / 2)) <= (H / 2)) {
		return true;
	}
	if (getDistance(x, y, X + W, Y + (H / 2)) <= (H / 2)) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> W >> H >> X >> Y >> P;

	int ans = 0;
	for (int i = 0; i < P; i++) {
		int x, y;
		cin >> x >> y;
		if (isInArea(x, y))ans++;
	}
	cout << ans;


}