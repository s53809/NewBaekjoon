#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

double getDistance(pair<int, int> x, pair<int, int> y) {
	return sqrt(((x.first - y.first) * (x.first - y.first)) + ((x.second - y.second) * (x.second - y.second)));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		vector<pair<int, int>> x(4);
		for (int i = 0; i < 4; i++) {
			cin >> x[i].first >> x[i].second;
		}

		map<double, int> dic;

		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (dic.find(getDistance(x[i], x[j])) == dic.end()) {
					dic.insert({ getDistance(x[i], x[j]), 1 });
				}
				else dic[getDistance(x[i], x[j])]++;
			}
		}

		if (dic.size() == 2) {
			bool isFour = false;
			bool isTwo = false;
			for (pair<double, int> temp : dic) {
				if (temp.second == 4) isFour = true;
				if (temp.second == 2) isTwo = true;
			}
			if (isFour && isTwo) { cout << "1\n"; continue; }
		}
		cout << "0\n";
	}
}