#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	int two = 0;
	int five = 0;
	
	for (int i = 2; i <= N; i++) {
		int box = i;

		while (box % 2 == 0) {
			box /= 2;
			two++;
		}
		while (box % 5 == 0) {
			box /= 5;
			five++;
		}
	}

	int ans = min(five, two);
	cout << ans;
}