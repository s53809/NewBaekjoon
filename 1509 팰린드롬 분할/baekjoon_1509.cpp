#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long int ll;
typedef vector<vector<ll>> vvll;

string str;
vvll dp;
int str_size;

bool isPalindrome(int strPos, int endPos) {
	if (strPos >= endPos) return true;
	if (str[strPos] == str[endPos - 1]) return isPalindrome(strPos + 1, endPos - 1);
	else return false;
}

ll Palin(int strPos, int endPos) { 
	ll& res = dp[strPos][endPos];
	if (res != 0) return res;
	if (strPos >= endPos) return 1;
	res = 1e9;
	for (int i = strPos; i < endPos; i++) {
		if (isPalindrome(i, endPos)) res = min(res, Palin(strPos, i) + 1);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> str;
	str_size = str.size();
	dp.resize(str_size + 1, vector<ll>(str_size + 1, 0));

	cout << Palin(0, str_size) - 1;
}