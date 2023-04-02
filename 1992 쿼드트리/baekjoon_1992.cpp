#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<vector<int>> x;

void quadTree(int xPos, int yPos, int num) {
	bool isSame = true;
	int value = x[yPos][xPos];
	for (int i = yPos; i < yPos + num; i++) {
		for (int j = xPos; j < xPos + num; j++) {
			if (value != x[i][j]) {
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}
	if (isSame) { cout << value; return; }
	
	cout << "(";

	int nextNum = num / 2;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			quadTree(xPos + (j * nextNum), yPos + (i * nextNum), nextNum);
		}
	}

	cout << ")";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;
	x.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			x[i][j] = str[j] - '0';
		}
	}

	quadTree(0, 0, N);
}