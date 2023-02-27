#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<pair<int,int>> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}
}