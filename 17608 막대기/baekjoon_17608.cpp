#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	stack<int> x;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (x.empty()) { //Ã¹ ÀÔ·Â
			x.push(a);
			continue;
		}
		if (x.top() > a) {
			x.push(a);
		}
		else {
			while (x.top() <= a) {
				x.pop();
				if (x.empty()) {
					break;
				}
			}
			x.push(a);
		}
	}

	cout << x.size();
}