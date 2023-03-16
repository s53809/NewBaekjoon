#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Field {
	int age;
	string name;
	int num;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<Field> x(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i].age >> x[i].name;
		x[i].num = i;
	}

	sort(x.begin(), x.end(), [](Field a, Field b) {
		if (a.age == b.age) {
			return a.num < b.num;
		}
		else {
			return a.age < b.age;
		}
		});

	for (int i = 0; i < N; i++) {
		cout << x[i].age << ' ' << x[i].name << '\n';
	}
}