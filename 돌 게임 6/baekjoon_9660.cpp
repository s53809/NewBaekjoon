#include <iostream>
typedef long long int lld;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	lld N;
	cin >> N;
	if (N % 7 == 0 || N % 7 == 2) cout << "CY";
	else cout << "SK";
}