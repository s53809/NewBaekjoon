#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> x;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		pair<int, int> input;
		cin >> input.first >> input.second;
		x[i] = input;
	}
	
	sort(x.begin(), x.end());
	for (int i = 0; i < N; i++) {
		cout << x[i].first << ' ' << x[i].second << '\n';
	}
}