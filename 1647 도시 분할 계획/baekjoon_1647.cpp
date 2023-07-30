#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int first, second, weight;
};


vector<Edge> x;
vector<int> uni;
vector<bool> visited;

int N, M;

int Find(int num) {
	if (uni[num] == -1) return num;
	else return uni[num] = Find(uni[num]);
}

void Merge(int a, int b) {
	int parentA = Find(a);
	int parentB = Find(b);

	if (parentA == parentB) return;

	uni[parentA] = parentB;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(M);
	uni.resize(N + 1, -1);
	visited.resize(N + 1, false);

	int ans = 0;
	int largeNum = 0;

	for (int i = 0; i < M; i++) {
		cin >> x[i].first >> x[i].second >> x[i].weight;
	}

	sort(x.begin(), x.end(), [](Edge a, Edge b) { return a.weight < b.weight; });

	for (int i = 0; i < M; i++) {
		if (Find(x[i].first) == Find(x[i].second)) continue;
		Merge(x[i].first, x[i].second);
		ans += x[i].weight;
		largeNum = max(largeNum, x[i].weight);
	}

	cout << ans - largeNum;
}