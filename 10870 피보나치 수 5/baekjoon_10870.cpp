#include <iostream>
#include <vector>
#define lld long long int
using namespace std;

vector<lld> x; // {-1, -1, -1, -1, -1, -1};

lld fibo(lld num) {
	if (x[num] != -1) return x[num];
	if (num == 1) return 1;
	if (num == 0) return 0;
	return x[num] = fibo(num - 1) + fibo(num - 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	x.resize(N + 1, -1);

	cout << fibo(N);
}