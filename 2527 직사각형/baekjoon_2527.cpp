#include <iostream>
using namespace std;

int x_1, y_1, p_1, q_1, x_2, y_2, p_2, q_2;

int Tangibleization(int x1, int x2, int p1, int p2) {
	if ((x1 < p1) && (p1 < x2) && (x2 < p2) || (x2 < p2) && (p2 < x1) && (x1 < p1)) {
		return 3;
	}
	else if ((p1 == x2) || (x1 == p2)) {
		return 2;
	}
	else if (((x1 < x2) && (x2 < p2) && (p2 < p1)) || ((x2 < x1) && (x1 < p1) && (p1 < p2))) {
		return 1;
	}
	else {
		return 1;
	}
}

char panstar() {
	int x_tang = Tangibleization(x_1, x_2, p_1, p_2);
	int y_tang = Tangibleization(y_1, y_2, q_1, q_2);

	//cout << x_tang << ' ' << y_tang << '\n';

	if (x_tang == 1) {
		if (y_tang == 1) {
			return 'a';
		}
		else if (y_tang == 2) {
			return 'b';
		}
		else {
			return 'd';
		}
	}
	else if (x_tang == 2) {
		if (y_tang == 1) {
			return 'b';
		}
		else if (y_tang == 2) {
			return 'c';
		}
		else {
			return 'd';
		}
	}
	else {
		return 'd';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++) {
		cin >> x_1 >> y_1 >> p_1 >> q_1 >> x_2 >> y_2 >> p_2 >> q_2;
		cout << panstar() << '\n';
	}
}