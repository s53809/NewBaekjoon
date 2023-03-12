#include <iostream>
using namespace std;

void Print() {
	cout << " @@@   @@@ \n";
	cout << "@   @ @   @\n";
	cout << "@    @    @\n";
	cout << "@         @\n";
	cout << " @       @ \n";
	cout << "  @     @  \n";
	cout << "   @   @   \n";
	cout << "    @ @    \n";
	cout << "     @     \n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		Print();
	}
}