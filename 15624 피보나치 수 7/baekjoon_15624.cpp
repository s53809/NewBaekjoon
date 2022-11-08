#include <iostream>
#include <vector>
#define lld long long int
using namespace std;

int N;
int x[3] = { 0,1,0 };

void pull() {
	x[0] = x[1];
	x[1] = x[2];
	x[2] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	if (N <= 1) {
		cout << x[N];
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		x[2] = (x[0] + x[1]) % 1000000007;
		pull();
	}

	cout << x[1];
}