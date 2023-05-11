#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cout << 1000 << '\n';

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 1000; i++) {
		cout << rand() % 100 + 1 << ' ';
	}
}