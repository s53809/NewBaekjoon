#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

string str;
int N;
bool x[10] = { false, };
int lowest_button = 2e9;

void Zaegwi(string& s, int num) {
	int sInt = stoi(s);
	lowest_button = min(abs(stoi(str) - sInt) + (int)s.size(), lowest_button);
	if (num == 0) return;

	for (int i = 0; i <= 9; i++) {
		if (!x[i]) {
			s += i + '0';
			Zaegwi(s, num - 1);
			s.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> str >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		x[n] = true;
	}

	for (int i = 0; i <= 9; i++) {
		if (!x[i]) {
			string comp = "";
			comp += i + '0';
			Zaegwi(comp, str.size());
			comp.pop_back();
		}
	}

	cout << min(lowest_button, abs(stoi(str) - 100));
}