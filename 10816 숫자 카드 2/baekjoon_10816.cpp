#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, int>> temp;
int N, M;
vector<int> x;
vector<int> y;
map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	cin >> M;
	y.resize(M);

	for (int i = 0; i < M; i++) {
		cin >> y[i];
	}

	sort(x.begin(), x.end());
	
	for (int i = 0; i < N; i++) {
		if (mp.find(x[i]) == mp.end()) {
			mp[x[i]] = 1;
		}
		else {
			mp[x[i]]++;
		}
		
	}

	for (int i = 0; i < M; i++) {
		if (mp.find(y[i]) == mp.end()) {
			cout << "0 ";
		}
		else {
			cout << mp[y[i]] << ' ';
		}
	}
}