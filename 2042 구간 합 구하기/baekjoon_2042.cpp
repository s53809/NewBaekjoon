#include <iostream>
#include <algorithm>
#define SIZE (1 << 20)
#define lld long long int
using namespace std;

int N, M, K;

struct SegTree {
	lld arr[SIZE];
	SegTree() { fill(arr, arr + SIZE, 0); }
	
	lld sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return arr[nodeNum];
		int mid = (nodeL + nodeR) / 2;
		return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M >> K;
}