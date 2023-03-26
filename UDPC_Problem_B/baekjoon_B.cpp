#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int U = 0, D = 0, P = 0;
string str;
int str_size;
map<char, int> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> str;
	str_size = str.size();

	for (int i = 0; i < str_size; i++) {
		if (str[i] == 'U') U++;
		else if (str[i] == 'D') D++;
		else if (str[i] == 'P') P++;
		else if (str[i] == 'C') U++;
	}


	U = 0; D = 0; P = 0;
	for (int i = 0; i < str_size; i++) {
		if (str[i] == 'U') U++;
		else if (str[i] == 'D') D++;
		else if (str[i] == 'P') D++;
	}
	
	U = 0; D = 0; P = 0;
	for (int i = 0; i < str_size; i++) {
		if (str[i] == 'U') U++;
		else if (str[i] == 'D') P++;
		else if (str[i] == 'P') P++;
	}

	if (ans.find('U') != ans.end()) cout << 'U';
	if (ans.find('D') != ans.end()) cout << 'D';
	if (ans.find('P') != ans.end()) cout << 'P';
}