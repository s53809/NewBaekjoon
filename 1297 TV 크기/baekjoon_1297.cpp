#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	double D, H, W;
	cin >> D >> H >> W;
	double x = sqrt((D * D) / ((H * H) + (W * W)));
	cout << floor(H * x) << ' ' << floor(W * x);
}