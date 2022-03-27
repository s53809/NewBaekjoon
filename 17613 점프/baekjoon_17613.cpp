#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<pair<int, int>> x;

int cal() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	x.resize(T);
	for (int i = 0; i < T; i++) {
		cin >> x[i].first >> x[i].second;
	}
	
}