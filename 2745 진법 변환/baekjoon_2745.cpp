#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int B;
	string N;
	cin >> N >> B;

	int ans = 0;
	for (int i = N.size() - 1, power = 0; i >= 0; i--, power++) {
		int box = 0;
		if ('0' <= N[i] && N[i] <= '9') box = N[i] - '0';
		else box = N[i] - 'A' + 10;
		ans += box * pow(B, power);
	}
	cout << ans;
}