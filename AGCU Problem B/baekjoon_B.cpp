#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int score[10] = { 512,256,128,64,32,16,8,4,2,1 };
	bool aScore[10] = { false, };
	bool bScore[10] = { false, };

	int A, B, C = 0;
	cin >> A >> B;

	for (int i = 0; i < 10; i++) {
		if (score[i] <= A) {
			A -= score[i];
			aScore[i] = true;
		}
		if (score[i] <= B) {
			B -= score[i];
			bScore[i] = true;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (aScore[i] != bScore[i]) C += score[i];
	}

	cout << C;
}