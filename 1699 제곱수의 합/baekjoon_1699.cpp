#include <iostream>
#include <cmath>
using namespace std;

int x[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		x[i] = i;
		for (int j = 1; j * j <= i; j++) {
			x[i] = min(x[i], x[i - j * j] + 1);
		}
	}
	cout << x[N];
}