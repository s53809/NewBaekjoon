#include <iostream>
using namespace std;

int uKlid(int a, int b) {
	if (!b) return a;
	return uKlid(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	int a, b;
	while (T--) {
		cin >> a >> b;
		int yakSu = uKlid(a, b);
		cout << (a * b) / yakSu << '\n';
	}

}