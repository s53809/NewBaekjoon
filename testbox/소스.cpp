#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int strPos, int imsi, int goal, int N) { //strPos에서 시작해서 imsi를 거쳐 goal로 가는 함수다
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