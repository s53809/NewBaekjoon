#include<iostream>
using namespace std;
int a = 0;
int b = 0;
int c = 0;
int main() {
	cin >> a;
	cin >> b;


	c = (a / 100) * 100;

	if (c % b == 0)
	{
		cout << "00";
		return 0;
	}
	else {
		for (int i = 1; i < 100; i++) {

			c += i;

			if (c % b == 0)
			{
				if (i < 10) {
					printf("0%d", c);
					return 0;
				}
				else {
					cout << i;
					return 0;
				}
			}
			c -= i;
		}

	}




}