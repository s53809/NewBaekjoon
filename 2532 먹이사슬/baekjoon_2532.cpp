#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> x;
vector<int> lis;

void Print() {
	for (int i = 0; i < lis.size(); i++) {
		cout << lis[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a >> x[i].first >> x[i].second;
	}

	sort(x.begin(), x.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return a.second > b.second;
		else return a.first < b.first;
		});

	x.erase(unique(x.begin(), x.end()), x.end());

	lis.push_back(-x[0].second);

	for (int i = 1, x_size = x.size(); i < x_size; i++) {
		if (-lis.back() >= x[i].second) {
			lis.push_back(-x[i].second);
		}
		else {
			int idx = upper_bound(lis.begin(), lis.end(), -x[i].second) - lis.begin();
			lis[idx] = -x[i].second;
		}
	}

	cout << lis.size();
}