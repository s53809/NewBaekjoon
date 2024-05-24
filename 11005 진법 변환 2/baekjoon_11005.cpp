#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	string ans;

	int N, B;
	cin >> N >> B;
	while(N != 0) {
		ans += str[N % B];
		N /= B;
	}
	
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
}