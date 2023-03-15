#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> x(5);
	int hap = 0;
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
		hap += x[i];
	}

	sort(x.begin(), x.end());

	cout << hap / 5 << '\n' << x[2];
}