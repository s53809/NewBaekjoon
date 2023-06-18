#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define lld long long int
#define SIZE (1 << 21)
using namespace std;

int N, M, K;

struct SegTree {
	vector<lld> arr;
	int size = 0;

	void Init(vector<lld>& input) {
		arr.resize(SIZE, 0);
		int i = 0;
		for (i = 1; pow(2, i) < N; i++) {}
		size = (int)pow(2, i);

		for (int i = 0; i < N; i++) {
			arr[i + size] = input[i];
		}

		UpdateAll(1);
	}

	lld UpdateAll(int num) {
		if (num >= size) return arr[num];
		return arr[num] = UpdateAll(num * 2) + UpdateAll(num * 2 + 1);
	}

	void InputValue(int num, lld val) {
		int index = (num - 1) + size;
		arr[index] = val;
		for (index /= 2; index >= 1; index /= 2) {
			arr[index] = arr[index * 2] + arr[index * 2 + 1];
		}
	}

	lld sum(int L, int R, int nodeIndex, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return arr[nodeIndex];
		int mid = (nodeL + nodeR) / 2;
		return sum(L, R, nodeIndex * 2, nodeL, mid) + sum(L, R, nodeIndex * 2 + 1, mid + 1, nodeR);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> K;
	vector<lld> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	SegTree seg;
	seg.Init(x);

	/*for (int i = 0; i < seg.size * 2; i++) cout << seg.arr[i] << ' ';
	cout << '\n';*/

	for (int i = 0; i < M + K; i++) {
		lld a, b, c;
		cin >> a >> b >> c;
		if (a == 1) seg.InputValue(b, c);
		else cout << seg.sum(b, c, 1, 1, N) << '\n';
		/*for (int j = 0; j < seg.size * 2; j++) cout << seg.arr[j] << ' ';
		cout << '\n';*/
	}
}