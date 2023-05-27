#include <iostream>
#include <bitset>
using namespace std;

bitset<33554432> bits;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int num;
	while (cin>>num) {
		if (!bits[num]) {
			bits[num] = 1;
			cout << num << ' ';
		}
	}
}