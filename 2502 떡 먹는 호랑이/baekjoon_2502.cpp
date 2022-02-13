#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int D, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> D >> K;

	vector<pair<int, int>> N;

	N.push_back(make_pair(1, 0));
	N.push_back(make_pair(0, 1));

	for (int i = 2; i < D; i++) {
		pair<int, int> sum;
		sum.first = N[i - 1].first + N[i - 2].first;
		sum.second = N[i - 1].second + N[i - 2].second;
		N.push_back(sum);
	}
	int length = N.size();

	pair<int, int> Num;
	Num = N[length - 1];

	for (int i = 1; i <= K / Num.first; i++) {
		if ((K - (Num.first * i)) % Num.second == 0) {
			cout << i << '\n' << (K - (Num.first * i)) / Num.second;
			break;
		}
	}
}