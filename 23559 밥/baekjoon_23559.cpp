#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, X;
	cin >> N >> X;
	vector<pair<int, int>> arr(N);
	set<int> visited;

	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
		X -= 1000;
	}

	sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) { return abs(a.first - a.second) > abs(b.first - b.second); });
	
	for (int i = 0; i < N; i++) {
		if (X >= 4000 && arr[i].first - arr[i].second >= 0) {
			X -= 4000;
			sum += arr[i].first - arr[i].second;
		}
	}

	cout << sum;
}