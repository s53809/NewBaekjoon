#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> x;
vector<int> day_cost;
void DP(int day, int cost) {
	
	if (day <= N + 1) {
		if (day_cost[day] < cost) day_cost[day] = cost;
		else if (day_cost[day] == 0);
		else return;
	}
	if (day > N) return;
	DP(day + x[day].first, cost + x[day].second); // 상담 할 때
	DP(day + 1, cost); // 상담 안할 때
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N + 1);
	day_cost.resize(N + 2);

	for (int i = 1; i <= N; i++) {
		cin >> x[i].first >> x[i].second;
		day_cost[i] = 0;
	}
	day_cost[N + 1] = 0;
	DP(1, 0);
	cout << day_cost[N + 1];
}