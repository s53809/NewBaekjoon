#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int x[46];
	x[0] = 0;
	x[1] = 1;

	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		x[i] = x[i - 2] + x[i - 1];
	}
	cout << x[N];
}