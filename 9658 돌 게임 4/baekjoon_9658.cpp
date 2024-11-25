#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;

int StoneGame(int i) {
	if (i == 0) return 1;
	if (i == 1) return 0;
	if (i == 2) return 1;
	if (dp[i] != -1) return dp[i];

	//��밡 ���� ����� ���� �����ؾ� ���� �̱�
	if (StoneGame(i - 1) == 0 ||
		((i > 3) && (StoneGame(i - 3) == 0)) ||
		((i > 4) && (StoneGame(i - 4) == 0))) return dp[i] = 1;
	else return dp[i] = 0;
	//�װ� �ƿ� ������ �й踦 ������ �޾Ƶ鿩�ߵ�
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	dp.resize(N + 1, -1);
	cout << (StoneGame(N) % 2 == 1 ? "SK" : "CY");
}