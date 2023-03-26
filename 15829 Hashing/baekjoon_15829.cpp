#include <iostream>
#include <string>
#include <cmath>
#define lld long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	string str;
	cin >> str;
	lld hap = 0;
	lld R = 1;

	for (int i = 0; i < N; i++) {
		hap += (((lld)(str[i] - 'a' + 1) * R) % 1234567891); hap %= 1234567891;
		R *= 31;
		R %= 1234567891;
	}

	cout << hap;
}