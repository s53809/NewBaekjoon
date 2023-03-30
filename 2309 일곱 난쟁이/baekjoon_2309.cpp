#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	vector<int> x(9);
	int hap = 0;

	for (int i = 0; i < 9; i++) {
		cin >> x[i];
		hap += x[i];
	}

	sort(x.begin(), x.end());
	pair<int, int> deleted;
	bool letsBreak = false;

	for (int i = 0; i < 8; i++) {	
		for (int j = i + 1; j < 9; j++) {
			if (hap - x[i] - x[j] == 100) {
				deleted = { i,j };
				letsBreak = true;
				break;
			}
		}
		if (letsBreak) break;
	}

	for (int i = 0; i < 9; i++) {
		if (i == deleted.first || i == deleted.second) continue;
		cout << x[i] << '\n';
	}
}