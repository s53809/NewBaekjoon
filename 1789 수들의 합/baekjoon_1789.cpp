#include <iostream>
#define lld long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	lld S;
	cin >> S;

	lld cnt = 0;
	for (lld i = 1; i <= S; i++) {
		cnt++;
		if (S - i <= i) break;
		S -= i;
	}
	cout << cnt;
}
