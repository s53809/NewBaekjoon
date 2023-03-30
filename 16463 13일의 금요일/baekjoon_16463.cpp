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
		yoIl = (yoIl + 12) % 7; // 1�� -> 13��
		if (yoIl == 4) ans++;
		if (curMonth == 2) {
			if (year % 400 == 0) maxMonth[2] = 29;
			else if (year % 100 == 0) maxMonth[2] = 28;
			else if (year % 4 == 0) maxMonth[2] = 29;
			else maxMonth[2] = 28;
		}
		yoIl = (yoIl + (maxMonth[curMonth] - 12)) % 7; // 13�� -> ���� �� 1��
		curMonth = ((curMonth + 1) % 13);
		if (curMonth == 0) { curMonth = 1; year++; }
	}

	cout << ans;
}

/*
2019�� 1�� 1���� ȭ�����̴�.
2���� 29�ϱ��� �����ϴ� �ظ� �����̶�� �Ѵ�.
�Ϲ������� 1������ 12���� ���� 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31�ϱ��� �ִ�. ������ �ؿ���, 2���� 28�ϱ����� �ƴ� 29�ϱ��� �ִ�.
400�� ��� ������ �����̴�.
400�� ����� �ƴϸ鼭 100�� ����� ������ ������ �ƴϴ�.
100�� ����� �ƴϸ鼭 4�� ����� ������ �����̴�.
�� ���� ������ ������ �ƴϴ�.
*/