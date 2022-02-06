#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> x;
vector<int> ranking;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	x.resize(N);
	ranking.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
		ranking[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (x[i].first < x[j].first && x[i].second < x[j].second)
				ranking[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ranking[i] << ' ';
	}
}