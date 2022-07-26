#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> x;
vector<int> box;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	box.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		box[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (x[i] > x[j]) {
				box[i] = max(box[i], box[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		//cout << box[i] << ' ';
		if (box[i] > ans) {
			ans = box[i];
		}
	}

	cout << ans + 1;
}