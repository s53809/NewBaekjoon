#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int N;
int maxSize = 0;
vector<vector<int>> x;
vector<int> xPos;
vector<int> yPos;
set<int> sorted_xPos;
set<int> sorted_yPos;
map<int, int> xDic;
map<int, int> yDic;

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void drawLine(int strPos, int endPos, int fixedValue, bool isXPos) {
	if (strPos > endPos) Swap(strPos, endPos);
	if (isXPos) {
		for (int i = xDic[strPos]; i <= xDic[endPos]; i++) {
			x[yDic[fixedValue]][i] = 1;
		}
	}
	else {
		for (int i = yDic[strPos]; i <= yDic[endPos]; i++) {
			x[i][xDic[fixedValue]] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	xPos.resize(N);
	yPos.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> xPos[i] >> yPos[i];
		sorted_xPos.insert(xPos[i]);
		sorted_yPos.insert(yPos[i]);
	}

	int it = 0;
	for (int iter : sorted_xPos) { xDic.insert({ iter, (it++ * 2) + 1 }); }
	it = 0;
	for (int iter : sorted_yPos) { yDic.insert({ iter, (it++ * 2) + 1 }); }
	it--;

	x.resize((it * 2) + 2, vector<int>((it * 2) + 2));

	for (int i = 1; i < N; i++) {
		bool isXPos = (xPos[i] != xPos[i - 1]);
		if (isXPos) drawLine(xPos[i - 1], xPos[i], yPos[i], isXPos);
		else drawLine(yPos[i - 1], yPos[i], xPos[i], isXPos);
	}

	bool lastIsXPos = (xPos[N - 1] != xPos[0]);
	if (lastIsXPos) drawLine(xPos[N - 1], xPos[0], yPos[0], lastIsXPos);
	else drawLine(yPos[N - 1], yPos[0], xPos[0], lastIsXPos);

}