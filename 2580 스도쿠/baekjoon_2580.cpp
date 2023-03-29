#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int x[9][9];

bool Sero(int posY, int posX) {
	bool check[10] = { false, };
	for (int i = 0; i < 9; i++) {
		check[x[i][posX]] = true;
	}

	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		if (ans != 0 && !check[i]) return false;
		else if (ans == 0 && !check[i]) ans = i;
	}

	x[posY][posX] = ans;
	return true;
}

bool Garo(int posY, int posX) {
	bool check[10] = { false, };
	for (int i = 0; i < 9; i++) {
		check[x[posY][i]] = true;
	}

	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		if (ans != 0 && !check[i]) return false;
		else if (ans == 0 && !check[i]) ans = i;
	}

	x[posY][posX] = ans;
	return true;
}

bool ThreePerThree(int posY, int posX) {
	bool check[10] = { false, };
	for (int i = (posY / 3) * 3; i < (posY / 3) + 3; i++) {
		for (int j = (posX / 3) * 3; j < (posX / 3) + 3; j++) {
			check[x[i][j]] = true;
		}
	}

	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		if (ans != 0 && !check[i]) return false;
		else if (ans == 0 && !check[i]) ans = i;
	}

	x[posY][posX] = ans;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	vector<pair<int,int>> search;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> x[i][j];
			if (x[i][j] == 0) search.push_back({ i,j });
		}
	}

	while (!search.empty()) {
		for (int i = search.size() - 1; i >= 0; i--) {
			if (Garo(search[i].first, search[i].second)) search.erase(search.begin() + i);
			else if (Sero(search[i].first, search[i].second)) search.erase(search.begin() + i);
			else if (ThreePerThree(search[i].first, search[i].second)) search.erase(search.begin() + i);
		}
	}

	cout << '\n';
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << x[i][j] << ' ';
		}
		cout << '\n';
	}
}