#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, W, H;
	cin >> N >> W >> H;

	double M = sqrt((W * W) + (H * H));
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		cout << ((n <= M) ? "DA" : "NE") << '\n';
	}
}