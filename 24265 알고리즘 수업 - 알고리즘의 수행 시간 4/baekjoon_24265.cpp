#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N;
	cin >> N;
	N -= 1;
	cout << (N * (N + 1)) / 2 << '\n' << 2;
}