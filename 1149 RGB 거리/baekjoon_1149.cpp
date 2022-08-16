#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<vector<int>> vec;
	vector<vector<int>> cost;
	cin >> N;
	vec.resize(N + 1);
	cost.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		vec[i].resize(3);
		cost[i].resize(3);

		cost[i][0] = 0;
		cost[i][1] = 0;
		cost[i][2] = 0;

		cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
	}

	cost[1][0] = vec[1][0];
	cost[1][1] = vec[1][1];
	cost[1][2] = vec[1][2];

	//cout << '\n' << cost[1][0] << ' ' << cost[1][1] << ' ' << cost[1][2] << '\n';
	for (int i = 2; i <= N; i++) {
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + vec[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + vec[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + vec[i][2];

		//cout << cost[i][0] << ' ' << cost[i][1] << ' ' << cost[i][2] << '\n';
	}

	int minimum = 2e9;

	for (int i = 0; i < 3; i++) {
		if (minimum > cost[N][i]) minimum = cost[N][i];
	}
	
	cout << minimum;
}