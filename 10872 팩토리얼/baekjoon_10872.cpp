#include <iostream>
using namespace std;

int func(int N) {
	if (N == 0) return 1;
	return N * func(N - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	cout << func(N);
}