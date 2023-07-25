#include <iostream>
#include <string>
using namespace std;

string x[8];

void Read(int yPos, int xPos) {
	for (int i = yPos; i < 8 && x[i][xPos] != '.'; i++) {
		cout << x[i][xPos];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	while (N--) {
		bool isFound = false;
		for (int i = 0; i < 8; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (x[i][j] != '.') {
					Read(i, j);
					cout << '\n';
					isFound = true;
					break;
				}
			}
			if (isFound) break;
		}
	}
}