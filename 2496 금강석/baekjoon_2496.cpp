#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, T, K;
vector<pair<int, int>> vec;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T >> K;

	for (int i = 0; i < T; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back(make_pair((M + (x - y)), (x + y)));
	}
}