#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int F;
		cin >> F;
		vector<pair<string, string>> x;
		x.resize(F);
		for (int i = 0; i < F; i++) {
			cin >> x[i].first >> x[i].second;
		}
	}
}