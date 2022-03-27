#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{

	int a[3];
	// (a * a) + (b * b)  = (c* c)
	while (1)
	{
		cin >> a[0] >> a[1] >> a[2];

		if (a[0] == 0 && a[1] == 0 && a[2] == 0) {
			break;
		}
		else
		{
			sort(a, a + 3);
			if ((a[0] * a[0]) + (a[1] * a[1]) == (a[2] * a[2]))
			{
				cout << "right" << '\n';
			}
			else {
				cout << "wrong" << '\n';
			}
		}

	}

	return 0;



}