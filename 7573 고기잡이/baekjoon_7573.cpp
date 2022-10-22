#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, I, M;

vector<pair<int, int>> map;

int areaGomsa(int str_x, int str_y, int x, int y) {
	int getsu = 0;
	for (int i = 0; i < M; i++) {
		if (map[i].first >= str_x && map[i].first <= x && map[i].second >= str_y && map[i].second <= y) {
			getsu++;
		}
	}
	return getsu;
}

int gomsa(int x, int y) {
	int ratio = I / 2;
	int maxGetsu = 0, prev = 0;
	for (int i = 1; i < ratio; i++) {
		int garoGomsa = i;
		int seroGomsa = (ratio - i);
		prev = maxGetsu;
		maxGetsu = max(areaGomsa(x, y, x + garoGomsa, y + seroGomsa), maxGetsu);
	}
	return maxGetsu;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> I >> M;

	map.resize(M);
	
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[i] = make_pair(a, b);
	}

	int maxGetsu = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			maxGetsu = max(gomsa(map[i].first, map[j].second), maxGetsu);
		}
	}

	cout << maxGetsu;
}