#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	N--;
	int chwaeDae = 1;
	int select = 1;
	int x[2] = { 1,1 };
	while (N--) {
		if (x[select] == chwaeDae) {
			chwaeDae++;
			x[select] = chwaeDae;
			select = 1 - select;
		}
		else {
			x[select]++;
			x[1 - select]--;
		}
	}

	cout << x[0] << "/" << x[1];
}