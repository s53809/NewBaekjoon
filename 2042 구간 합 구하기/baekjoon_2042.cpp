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

ll sum(vll& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) 
		+ sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vll& tree, int node, int start, int end, int idx, ll diff) {
	if (idx < start || idx > end) return;
	tree[node] += diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, idx, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> K;

	vll arr(N);
	vll tree;

	ll H = ceil(log2(N)) + 1;
	ll size = (1 << H) + 1;

	tree.resize(size);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(arr, tree, 1, 0, N - 1);
	
	for (int i = 0; i < M + K; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) { 
			update(tree, 1, 0, N - 1, b - 1, c - arr[b - 1]); 
			arr[b - 1] = c;
		}
		else cout << sum(tree, 1, 0, N - 1, b - 1, c - 1) << '\n';
	}
}