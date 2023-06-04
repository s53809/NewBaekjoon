#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string str;
int str_size = 0;
vector<int> dp;

int twoZari(int startPos) {
	return ((int)(str[startPos] - '0') * 10) + (int)(str[startPos + 1] - '0');
}

int Card(int N) {
	if (N == 1) return 1;
	if (N == 2) return (twoZari(0) > 34 || str[1] == '0') ? 1 : 2;
	if (dp[N] != 0) return dp[N];

	if (str[N - 1] != '0') dp[N] += Card(N - 1); //일의 자리가 0인 경우는 패스
	if (str[N - 2] != '0' && twoZari(N - 2) <= 34) dp[N] += Card(N - 2);
	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> str;
	str_size = str.size();
	dp.resize(str_size + 1, 0);

	cout << Card(str_size) << '\n';
}