#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	
	vector<pair<string, int>> arr = {
		make_pair("c=", 1),
		make_pair("c-",1),
		make_pair("dz=",2),
		make_pair("d-",1),
		make_pair("lj",1),
		make_pair("nj",1),
		make_pair("s=",1),
		make_pair("z=",1)
	};

	for (int i = 0, arr_size = arr.size(); i < arr_size; i++) {
		if (str.find(arr[i].first) != string::npos) {
			str.replace(str.find(arr[i].first), arr[i].first.length(), "#");
			i--;
		}
	}

	cout << str.length();
}