#include <iostream>
using namespace std;

int facto(int a) {
	int ans = 1;
	for (int i = a; i >= 1; i--) {
		ans *= i;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;

	cout << facto(N) / (facto(N - K) * facto(K));
}