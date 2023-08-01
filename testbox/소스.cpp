#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	vector<float> x(100);

	for (int i = 0; i < 100; i++) {
		cin >> x[i];
	}

	cout << "[";
	for (int i = 0; i < 100; i++) {
		if (i == 99) printf("%.2f", x[i]);
		else printf("%.2f, ", x[i]);
	}
	cout << "]\n";
}