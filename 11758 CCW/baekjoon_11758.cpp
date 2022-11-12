#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pair<int, int> x[3];
	for (int i = 0; i < 3; i++) {
		cin >> x[i].first >> x[i].second;
	}
	int value = (x[0].first * x[1].second) + (x[1].first * x[2].second) + (x[2].first * x[0].second)
		- ((x[1].first * x[0].second) + (x[2].first * x[1].second) + (x[0].first * x[2].second));
	if (value < 0) {
		cout << "-1";
	}
	else if (value == 0) {
		cout << "0";
	}
	else {
		cout << "1";
	}
}