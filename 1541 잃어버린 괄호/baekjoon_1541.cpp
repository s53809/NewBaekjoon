#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> str;

	int hap = 0;
	int startPos = 0;
	int nextCal = -1; // 0 : +, 1 : -
	int stackBomb = 0;
	for (int i = 0, str_size = str.size(); i < str_size; i++) {
		//cout << "hap: " << hap << '\n';
		if (str[i] == '+') {
			//cout << "+" << stoi(str.substr(startPos, (i - 1) - startPos + 1)) << '\n';
			if (nextCal == -1) { hap = stoi(str.substr(startPos, (i - 1) - startPos + 1)); nextCal = 0; }
			else if (nextCal == 0) { hap += stoi(str.substr(startPos, (i - 1) - startPos + 1)); }
			else if (nextCal == 1) { stackBomb += stoi(str.substr(startPos, (i - 1) - startPos + 1)); nextCal = 1; }
			startPos = i + 1;
		}
		else if (str[i] == '-') {
			//cout << "-" << stoi(str.substr(startPos, (i - 1) - startPos + 1)) << '\n';
			if (nextCal == -1) { hap = stoi(str.substr(0, (i - 1) - startPos + 1)); nextCal = 1; }
			else if (nextCal == 0) { hap += stoi(str.substr(startPos, (i - 1) - startPos + 1)); nextCal = 1; }
			else if (nextCal == 1) { hap -= (stackBomb + stoi(str.substr(startPos, (i - 1) - startPos + 1))); stackBomb = 0; }
			startPos = i + 1;
		}
		else if (i == str_size - 1) {
			//cout << "last" << stoi(str.substr(startPos, i - startPos + 1)) << '\n';
			if (nextCal == 0 || nextCal == -1) {
				hap += stoi(str.substr(startPos, i - startPos + 1));
			}
			else if (nextCal == 1) {
				stackBomb += stoi(str.substr(startPos, i - startPos + 1));
			}
		}
	}

	hap -= stackBomb;
	cout << hap;
}