#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	bool isPalin = true;

	for (int i = 0, str_size = str.size(), j = str_size - 1; i < str_size; i++, j--) {
		if (str[i] != str[j]) { isPalin = false; break; }
	}

	cout << isPalin ? "1" : "0";
}