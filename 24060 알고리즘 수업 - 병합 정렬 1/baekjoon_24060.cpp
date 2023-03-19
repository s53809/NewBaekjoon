#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x;
vector<int> sapip;
int N, K;

void mearge(int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;
	static vector<int> temp(N + 1);
	while (i <= q && j <= r) {
		if (x[i] <= x[j]) { 
			temp[t] = x[i++];
			sapip.push_back(temp[t]);
			t++;
		}
		else { 
			temp[t] = x[j++]; 
			sapip.push_back(temp[t]);
			t++;
		}
	}
	while (i <= q) {
		temp[t] = x[i++];
		sapip.push_back(temp[t]);
		t++;
	}
	while (j <= r) {
		temp[t] = x[j++];
		sapip.push_back(temp[t]);
		t++;
	}
	i = p;
	t = 1;
	while (i <= r) {
		x[i++] = temp[t++];
	}
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		mearge(p, q, r);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	x.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> x[i];
	}

	merge_sort(1, N);
	if (K - 1 > sapip.size() - 1) {
		cout << "-1";
	}
	else {
		cout << sapip[K - 1];
	}
}