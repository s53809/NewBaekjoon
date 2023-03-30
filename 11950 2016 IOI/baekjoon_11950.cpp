#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string W = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";
string B = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
string R = "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";
int N, M;
vector<string> x;

int gomsa(int posY, string& comp) {
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (x[posY][i] != comp[i]) {
			ans++;
		}
	}
	return ans;
}

int Coloring(int minY, int maxY, string& comp) {
	int hap = 0;
	for (int i = minY; i < maxY; i++) {
		hap += gomsa(i, comp);
	}
	return hap;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	int hap = 2e9;
	for (int i = 1; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			hap = min(hap, Coloring(0, i, W) + Coloring(i, j, B) + Coloring(j, N, R));
		}
	}

	cout << hap;
}