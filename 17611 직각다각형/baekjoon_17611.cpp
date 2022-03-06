#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> x;
vector<int> xPos;
vector<int> yPos;
int xUp = 0, yUp = 0;
int xtop = 2e9 * -1, ytop = 2e9 * -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) { // nUp은 최솟값 ntop은 최댓값
		cin >> x[i].first >> x[i].second;
		if (x[i].first < xUp) xUp = x[i].first;
		if (x[i].second < yUp) yUp = x[i].second;
		if (x[i].first > xtop) xtop = x[i].first;
		if (x[i].second > ytop) ytop = x[i].second;
	}
	xPos.resize(xtop + (xUp * -1));
	yPos.resize(ytop + (yUp * -1));
	fill(xPos.begin(), xPos.end(), 0);
	fill(yPos.begin(), yPos.end(), 0);
	for (int i = 0; i < N - 1; i++) {
		int startPos = 0;
		int endPos = 0;
		int isThisXPosOrYPosifXPosInputOneElseIfYPosInputTwoThenIWillCalculate = 0;
		if (x[i].first != x[i + 1].first) {
			isThisXPosOrYPosifXPosInputOneElseIfYPosInputTwoThenIWillCalculate = 1;
			if (x[i].first > x[i + 1].first) {
				startPos = x[i + 1].first;
				endPos = x[i].first;
			}
			else {
				endPos = x[i + 1].first;
				startPos = x[i].first;
			}
		}
		else {
			isThisXPosOrYPosifXPosInputOneElseIfYPosInputTwoThenIWillCalculate = 2;
			if (x[i].second > x[i + 1].second) {
				startPos = x[i + 1].second;
				endPos = x[i].second;
			}
			else {
				endPos = x[i + 1].second;
				startPos = x[i].second;
			}
		}
		for (int j = startPos; j < endPos; j++) {
			if (isThisXPosOrYPosifXPosInputOneElseIfYPosInputTwoThenIWillCalculate == 1) {
				xPos[j + (xUp * -1)]++;
			}
			else {
				yPos[j + (yUp * -1)]++;
			}
		}
	}
	//여기서부터는 끝점과 첫번째 점의 xPos yPos 비교입니다
	int isthisblabla = 0;
	int strPos = 0;
	int endPos = 0;
	if (x[N - 1].first != x[0].first) {
		isthisblabla = 1;
		if (x[N - 1].first > x[0].first) {
			strPos = x[0].first;
			endPos = x[N - 1].first;
		}
		else {
			strPos = x[N - 1].first;
			endPos = x[0].first;
		}
	}
	else {
		isthisblabla = 2;
		if (x[N - 1].second > x[0].second) {
			strPos = x[0].second;
			endPos = x[N - 1].second;
		}
		else {
			strPos = x[N - 1].second;
			endPos = x[0].second;
		}
	}
	for (int j = strPos; j < endPos; j++) {
		if (isthisblabla == 1) {
			xPos[j + (xUp * -1)]++;
		}
		else {
			yPos[j + (yUp * -1)]++;
		}
	} // h v 찾기
	int h = 0, v = 0;
	int xLength = xPos.size();
	int yLength = yPos.size();
	int topLength = max(xLength, yLength);
	for (int i = 0; i < topLength; i++) {
		if (i < xLength) {
			if (h < xPos[i]) h = xPos[i];
		}
		if (i < yLength) {
			if (v < yPos[i]) v = yPos[i];
		}
	}
	cout << max(h, v);
}