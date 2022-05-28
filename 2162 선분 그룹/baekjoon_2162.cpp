#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<pair<int, int>, pair<int, int>>> x;
vector<int> root;
vector<int> height;
vector<int> ans;

int find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return root[x] = find(root[x]);
	}
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);

	if(x == y) return;
	if (height[x] < height[y]) {
		root[x] = y;
	}
	else {
		root[y] = x;

		if (height[x] == height[y])
			height[x]++;
	}
}

int CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int num = a.first * b.second + b.first * c.second + c.first * a.second;
	num -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (num > 0) return 1;
	else if (num == 0) return 0;
	else return -1;
}

int cal(pair<pair<int, int>, pair<int, int>> strNum, pair<pair<int, int>, pair<int, int>> endNum) {
	pair<int, int> a = strNum.first;
	pair<int, int> b = strNum.second;
	pair<int, int> c = endNum.first;
	pair<int, int> d = endNum.second;

	int num1 = CCW(a, b, c) * CCW(a, b, d);
	int num2 = CCW(c, d, a) * CCW(c, d, b);
	if (num1 == 0 && num2 == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d); //겹침 유무를 구하기 위한 대소비교
		if (c <= b && a <= d) return 1;
		else return 0;
	}
	if (num1 <= 0 && num2 <= 0) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	root.resize(N);
	ans.resize(N);
	height.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first.first >> x[i].first.second >> x[i].second.first >> x[i].second.second;
		root[i] = i;
		ans[i] = 0;
		height[i] = 0;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (cal(x[i], x[j]) == 1) {
				uni(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		find(i);
		ans[root[i]]++;
	}
	int maxNum = 0;
	int getsu = 0;
	for (int i = 0; i < N; i++) {
		if (ans[i] != 0) {
			getsu++;
		}
		if (ans[maxNum] < ans[i]) {
			maxNum = i;
		}
	}

	cout << getsu << '\n' << ans[maxNum] << '\n';
}