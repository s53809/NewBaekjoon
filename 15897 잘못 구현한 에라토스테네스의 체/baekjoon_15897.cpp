#include <iostream>
typedef long long int lld;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n;
	cin >> n;

	lld cnt = 0;

	for (int i = n; i >= 1; i--) {
		if (n % i == 0) {
			cnt += n / i;
		}
		else {
			int value = n / ((n / i) + 1);
			if (n % ((n / i) + 1) != 0) value++;
			cnt += ((i - value) + 1) * ((n / i) + 1);
			i = value;
		}
	}
	cout << cnt;
}