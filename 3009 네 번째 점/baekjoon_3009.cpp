#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int xPos[2] = { 0,0 };
	int yPos[2] = { 0,0 };
	for (int i = 0; i < 3; i++) {
		int xInput, yInput;
		cin >> xInput >> yInput;
		if (xPos[0] == 0) {
			xPos[0] = xInput;
		}
		else if (xPos[0] == xInput) {
			xPos[0] = 0;
		}
		else {
			if (xPos[1] == xInput) {
				xPos[1] = 0;
			}
			else {
				xPos[1] = xInput;
			}
		}

		if (yPos[0] == 0) {
			yPos[0] = yInput;
		}
		else if (yPos[0] == yInput) {
			yPos[0] = 0;
		}
		else {
			if (yPos[1] == yInput) {
				yPos[1] = 0;
			}
			else {
				yPos[1] = yInput;
			}
		}
	}

	if (xPos[0] == 0) cout << xPos[1] << ' ';
	else cout << xPos[0] << ' ';

	if (yPos[0] == 0) cout << yPos[1];
	else cout << yPos[0];
}