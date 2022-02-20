#include <iostream>
#include <string>
using namespace std;

string str;
bool isPalin;
bool isUsaPalin;

void SearchPalin(int i, int j, bool isUsa) {
	if (i > j) {
		isPalin = true;
		return;
	}
	if (str[i] == str[j]) SearchPalin(i + 1, j - 1, isUsa);
	else if (!isUsa) {
		if (str[i + 1] == str[j]) {
			isUsaPalin = true;
			SearchPalin(i + 2, j - 1, true);
		}
		if (str[i] == str[j - 1]) {
			isUsaPalin = true;
			SearchPalin(i + 1, j - 2, true);
		}
		if (!isUsaPalin) return;
	}
	else return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int cnt = 0; cnt < N; cnt++) {
		cin >> str;
		int i = 0;
		int j = str.size() - 1;
		isPalin = false;
		isUsaPalin = false;
		SearchPalin(i, j, false);
		if (isPalin) {
			if (isUsaPalin) cout << "1\n";
			else cout << "0\n";
		}
		else cout << "2\n";
	}
}