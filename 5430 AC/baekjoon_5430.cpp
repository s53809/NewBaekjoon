#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		string code;
		int N;
		string ar;
		vector<int> arr;
		cin >> code;
		cin >> N;
		cin >> ar;
		
		int idx = 1;
		int ar_size = ar.size();
		string temp = "";
		while (idx < ar_size - 1) {
			if (ar[idx] == ',') {
				arr.push_back(stoi(temp));
				temp = "";
			}
			else {
				temp += ar[idx];
			}
			idx++;
		}
		if(temp != "") arr.push_back(stoi(temp));

		bool isReverse = false;
		bool isError = false;
		int startIdx = 0;
		int endIdx = arr.size() - 1;

		for (int i = 0, code_size = code.size(); i < code_size; i++) {
			if (code[i] == 'R') {
				isReverse = !isReverse;
			}
			if (code[i] == 'D') {
				if (startIdx > endIdx) { isError = true; break; }
				if (isReverse) endIdx--;
				else startIdx++;
			}
		}
		if (isError) { cout << "error\n"; continue; }

		if (isReverse) {
			cout << "[";
			for (int i = endIdx; i >= startIdx; i--) {
				cout << arr[i];
				if (i != startIdx) cout << ",";
			}
			cout << "]\n";
		}
		else {
			cout << "[";
			for (int i = startIdx; i <= endIdx; i++) {
				cout << arr[i];
				if (i != endIdx) cout << ",";
			}
			cout << "]\n";
		}
	}
}