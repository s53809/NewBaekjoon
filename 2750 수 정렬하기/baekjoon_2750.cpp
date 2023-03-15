#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x.begin(),x.end());
	for (int i = 0; i < N; i++) {
		cout << x[i] << '\n';
	}
}