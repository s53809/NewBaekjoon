#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> x;
pair<int, int> maxX = make_pair(0, 0);
pair<int, int> maxY = make_pair(0, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(6);

	for (int i = 0; i < 6; i++) {
		cin >> x[i].first >> x[i].second;
		if (x[i].first == 1 || x[i].first == 2) {
			if (maxX.first < x[i].second) {
				maxX.first = x[i].second;
				maxX.second = i;
			}
		}
		else {
			if (maxY.first < x[i].second) { 
				maxY.first = x[i].second; 
				maxY.second = i;
			}
		}
	}

	int nerbe = maxX.first * maxY.first;

	if (x[(maxX.second + 1) % 6].second == maxY.first) {
		cout << (nerbe - (x[(maxX.second + 3) % 6].second * x[(maxX.second + 4) % 6].second)) * N;
	}
	else {
		cout << (nerbe - (x[(maxX.second + 2) % 6].second * x[(maxX.second + 3) % 6].second)) * N;
	}
}