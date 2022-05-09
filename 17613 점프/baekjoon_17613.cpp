#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<pair<int, int>> x;
int length = 0;
vector<int> cnt;
vector<pair<int, int>> hiPass;
int hiPass_length = 0;

int cal(int N) {
	if (cnt[N] != 0) return cnt[N];
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	x.resize(T);
	for (int i = 0; i < T; i++) {
		cin >> x[i].first >> x[i].second;
		if (length < x[i].second) length = x[i].second;
	}
	int getsu = 1;
	cnt.resize(length + 1);
	fill(cnt.begin(), cnt.end(), 0);
	int box = 1;
	while (box > length) {
		cnt[box] = getsu;
		hiPass.push_back(make_pair(box, getsu));
		getsu++;
		box *= 2;
	}
	hiPass_length = hiPass.size();
}