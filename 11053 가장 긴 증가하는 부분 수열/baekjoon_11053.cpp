#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
	
int N;
vector<int> x;
vector<int> leng;
int ans = 0;

void print() {
	for (int i = 0, leng_size = leng.size(); i < leng_size; i++) {
		cout << leng[i] << '\n';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	leng.push_back(x[0]);

	for (int i = 1; i < N; i++) {
		if ((*(leng.end() - 1)) < x[i]) {
			leng.push_back(x[i]);
		}
		else {
			vector<int>::iterator low;
			low = lower_bound(leng.begin(), leng.end(), x[i]);
			(*low) = x[i];
			//print();
		}
	}
	
	cout << leng.size();
}