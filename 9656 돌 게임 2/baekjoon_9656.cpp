#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	cout << ((N % 2 == 1) ? "CY" : "SK");
}