#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
typedef std::pair<double, double> pii;
using namespace std;

int N;
vector<pii> x;
bool visited[21] = { false };
double ans = 2e9;

double VecHap() {
	pii temp = { 0,0 };
	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			temp.first -= x[i].first;
			temp.second -= x[i].second;
		}
		else {
			temp.first += x[i].first;
			temp.second += x[i].second;
		}
	}
	return sqrt((temp.first * temp.first) + (temp.second * temp.second));
}

void DFS(int index, int cnt) {
	if (cnt == N / 2) {
		ans = min(ans, VecHap());
		return;
	}

	for (int i = index; i < N; i++) {
		visited[index] = true;
		DFS(i + 1, cnt + 1);
		visited[index] = false;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		x.clear();
		cin >> N;
		x.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> x[i].first >> x[i].second;
		}
		fill(visited, visited + 21, false);
		ans = 2e9;

		DFS(0, 0);
		printf("%.7lf\n", ans);
	}
}