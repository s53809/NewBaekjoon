#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

struct Island {
	int dist;
	int spring;
	int isDandan;
};

int N;
vector<Island> x;
vector<vector<int>> dp;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].dist >> x[i].spring >> x[i].isDandan;
	}
}