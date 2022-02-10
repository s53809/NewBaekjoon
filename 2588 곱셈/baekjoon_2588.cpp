#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	
	cin >> N >> M;

	cout << N * (M % 10) << '\n' << N * (M % 100 / 10) << '\n' << N * (M / 100) << '\n' << N * M;
}