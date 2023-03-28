#include <iostream>
#include <cmath>
using namespace std;

void printKantor(int N, bool isSpace) {
	if (N == 0 && !isSpace) {
		cout << "-";
		return;
	}
	else if (N == 0 && isSpace) {
		cout << " ";
		return;
	}

	int num = pow(3, N - 1);
	printKantor(N - 1, isSpace);
	printKantor(N - 1, true);
	printKantor(N - 1, isSpace);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	while (cin >> N) {
		printKantor(N, false);
		cout << '\n';
	}
}