#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++) {
		cout << rand() % 2000000000 << ' ';
	}
}