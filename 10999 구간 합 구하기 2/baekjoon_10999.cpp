#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;

int N, M, K;

ll init(vll& arr, vll& tree, int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) 
		+ init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}


void update_lazy(vll& tree, vll& lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

ll sum(vll& tree, vll& lazy, int node, int start, int end, int left, int right) {
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return tree[node];
	return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right)
		+ sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vll& tree, vll& lazy, int node, int start, int end, int left, int right, ll diff) {
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		tree[node] += diff * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
	update(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M >> K;
	vll arr(N);

	int H = ceil(log2(N)) + 1;
	int size = (1 << H) + 1;

	vll tree(size, 0);
	vll lazy(size, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(arr, tree, 1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		ll a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(tree, lazy, 1, 0, N - 1, b - 1, c - 1, d);
		}
		else {
			cin >> b >> c;
			cout << sum(tree, lazy, 1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}
}