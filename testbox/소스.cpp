#include <iostream>
using namespace std;

int arr[50];
int a, b, c = 0;
int d = 1;
int e = 0;
int t = 0;
int q = 0;

int main() {
	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> arr[i];
	}
	if (a == 1) {
		cout << 0;
		return 0;
	}
	for (q = 1; q < a; q++) {
		if (arr[0] > arr[q]) {

			b++;
		}
	}
	if (b == q - 1) {
		cout << 0;
		return 0;
	}

	while (true) {
		b = 0;
		for (int y = 1; y < a; y++)
		{
			if (arr[d] <= arr[y])
			{
				d = y;
			}
		}
		for (t = 1; t < a; t++) {
			if (arr[0] > arr[t]) {

				b++;
			}
		}
		if (b == t - 1) {
			cout << e;
			return  0;
		}
		else {
			arr[d] = arr[d] - 1;
			arr[0] = arr[0] + 1;
			e++;
		}
	}

}