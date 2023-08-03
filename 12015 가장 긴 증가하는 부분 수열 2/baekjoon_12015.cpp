#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	vector<int> leng;
	leng.push_back(x[0]);

	for (int i = 1; i < N; i++) {
		if (*(leng.end() - 1) < x[i])leng.push_back(x[i]);
		else {
			auto iter = lower_bound(leng.begin(), leng.end(), x[i]);
			*iter = x[i];
		}
	}
	cout << leng.size();
}