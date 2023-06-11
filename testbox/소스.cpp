#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int strPos, int imsi, int goal, int N) { //strPos���� �����ؼ� imsi�� ���� goal�� ���� �Լ���
	if (N == 0) return;
	hanoi(strPos, goal, imsi, N - 1);
	cout << strPos << ' ' << goal << '\n';
	hanoi(imsi, strPos, goal, N - 1);
}

int main() {
	int N;
	cin >> N;

	cout << (int)(pow(2, N) - 1) << '\n'; // 2^N - 1
	hanoi(1, 2, 3, N);
}