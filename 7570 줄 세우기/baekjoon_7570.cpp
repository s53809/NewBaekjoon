#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr;
int check[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		check[arr[i]] = 0;
	}

	int maxValue = 0;

	for (int i = 0; i < N; i++) {
		check[arr[i]] = check[arr[i] - 1] + 1;
		maxValue = max(maxValue, check[arr[i]]);
	}

	cout << N - maxValue;
}