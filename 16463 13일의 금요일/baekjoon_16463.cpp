#include <iostream>
using namespace std;

int year = 2019;
int maxYear = 0;
int maxMonth[] = { 0, 31, 28,31,30,31,30,31,31,30,31,30,31 };
int curMonth = 1;
int yoIl = 1; // 6

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> maxYear;
	int ans = 0;

	for (year = 2019; year <= maxYear;) {
		yoIl = (yoIl + 12) % 7; // 1일 -> 13일
		if (yoIl == 4) ans++;
		if (curMonth == 2) {
			if (year % 400 == 0) maxMonth[2] = 29;
			else if (year % 100 == 0) maxMonth[2] = 28;
			else if (year % 4 == 0) maxMonth[2] = 29;
			else maxMonth[2] = 28;
		}
		yoIl = (yoIl + (maxMonth[curMonth] - 12)) % 7; // 13일 -> 다음 달 1일
		curMonth = ((curMonth + 1) % 13);
		if (curMonth == 0) { curMonth = 1; year++; }
	}

	cout << ans;
}

/*
2019년 1월 1일은 화요일이다.
2월이 29일까지 존재하는 해를 윤년이라고 한다.
일반적으로 1월부터 12월은 각각 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31일까지 있다. 윤년인 해에는, 2월이 28일까지가 아닌 29일까지 있다.
400의 배수 연도는 윤년이다.
400의 배수가 아니면서 100의 배수인 연도는 윤년이 아니다.
100의 배수가 아니면서 4의 배수인 연도는 윤년이다.
그 외의 연도는 윤년이 아니다.
*/