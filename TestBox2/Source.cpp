#include<iostream>
using namespace std;
int a;
int c;
int b = 0;
int fac(int fa) {
	if (fa == 1) {
		while (true)
		{
			if (c % 10 != 0) {
				cout << b;
				return 0;
			}
			else {
				c = c / 10;
				b++;
			}
		}
	}
	fa = fa - 1;
	c = c * fa;

	return fac(fa);
}
int main() {
	cin >> a;
	c = a;
	if (a == 0) {
		cout << '0';
		return 0;
	}
	fac(a);
	return 0;
}