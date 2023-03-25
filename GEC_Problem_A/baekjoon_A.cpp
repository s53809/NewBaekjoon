#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, string> dic;
	dic.insert({ "NLCS", "North London Collegiate School" });
	dic.insert({ "BHA", "Branksome Hall Asia" });
	dic.insert({ "KIS", "Korea International School" });
	dic.insert({ "SJA", "St. Johnsbury Academy" });

	string str;
	cin >> str;
	cout << dic[str];
}