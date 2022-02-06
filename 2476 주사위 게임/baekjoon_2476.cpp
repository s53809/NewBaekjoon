#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int maximum = 0;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		int money;
		cin >> a >> b >> c;
		if (a == b && a == c) {
			money = 10000 + (a * 1000);
			if (maximum < money) {
				maximum = money;
			}
		}
		else if (a == b || a == c || b == c) {
			if (a != b) {
				money = 1000 + (c * 100);
			}
			else {
				money = 1000 + (a * 100);
			}
			if (maximum < money) {
				maximum = money;
			}
		}
		else {
			int maxNum = a;
			if (maxNum < b) {
				maxNum = b;
			}
			if (maxNum < c) {
				maxNum = c;
			}
			money = maxNum * 100;
			if (maximum < money) {
				maximum = money;
			}
		}
	}
	cout << maximum;
}