#include <iostream>
#include <string>
using namespace std;

int solve_Hap(string& s) {
	int hap = stoi(s);
	for (int i = 0, N_size = s.size(); i < N_size; i++) {
		hap += s[i] - '0';
	}
	return hap;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	string N;
	cin >> N;

	int ans = stoi(N);
	int i = 1;

	for (; i <= 1000000; i++) {
		string str = to_string(i);
		if (solve_Hap(str) == ans) {
			cout << i;
			break;
		}
	}
	if (i == 1000001)cout << "0";
}