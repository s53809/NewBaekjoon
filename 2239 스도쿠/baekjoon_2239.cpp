#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<pair<int, int>> vll;

vector<string> x(9);
vector<vector<int>> garo(10, vector<int>(10, 0));
vector<vector<int>> sero(10, vector<int>(10, 0));
vector<vector<vector<int>>> threeByThree(3, vector<vector<int>>(3, vector<int>(10, 0)));
vll inputs;
int input_size = 0;
bool isAnswer = false;

void checkSudoku(int N) {
	//cout << N << '\n';
	if (N == input_size) {
		for (int i = 0; i < 9; i++) {
			cout << x[i] << '\n';
		}
		isAnswer = true;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (isAnswer) return;
		int xPos = inputs[N].first;
		int yPos = inputs[N].second;
		x[yPos][xPos] = i + '0';
		if (garo[yPos][i] == 0 && sero[xPos][i] == 0 && threeByThree[yPos / 3][xPos / 3][i] == 0) {
			garo[yPos][i] = 1;
			sero[xPos][i] = 1;
			threeByThree[yPos / 3][xPos / 3][i] = 1;
			checkSudoku(N + 1);
			garo[yPos][i] = 0;
			sero[xPos][i] = 0;
			threeByThree[yPos / 3][xPos / 3][i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 0; i < 9; i++) {
		cin >> x[i];
		for (int j = 0; j < 9; j++) {
			if (x[i][j] == '0') { inputs.push_back({ j,i }); input_size++; }
			else {
				garo[i][x[i][j] - '0'] = 1;
				sero[j][x[i][j] - '0'] = 1;
				threeByThree[i / 3][j / 3][x[i][j] - '0'] = 1;
			}
		}
	}

	//cout << inputs.size() << " " << input_size << '\n';

	checkSudoku(0);
}