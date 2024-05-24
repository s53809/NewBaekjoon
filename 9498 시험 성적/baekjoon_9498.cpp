#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	if (90 <= N && N <= 100) cout << "A";
	else if (80 <= N && N <= 89) cout << "B";
	else if (70 <= N && N <= 79) cout << "C";
	else if (60 <= N && N <= 69) cout << "D";
	else cout << "F";
}