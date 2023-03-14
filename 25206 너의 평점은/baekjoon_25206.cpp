#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	float finalHakScore = 0;
	float finalScore = 0;

	vector<pair<string, float>> rankScore = {
		make_pair("A+",4.5),
		make_pair("A0",4.0),
		make_pair("B+",3.5),
		make_pair("B0",3.0),
		make_pair("C+",2.5),
		make_pair("C0",2.0),
		make_pair("D+",1.5),
		make_pair("D0",1.0),
		make_pair("F",0.0),
	};

	for (int i = 0; i < 20; i++) {
		string str;
		float hakScore;
		string rank;
		cin >> str >> hakScore >> rank;
		if (rank == "P") continue;
		finalHakScore += hakScore;

		for (int j = 0, rank_size = rankScore.size(); j < rank_size; j++) {
			if (rank == rankScore[j].first) {
				finalScore += rankScore[j].second * hakScore;
				break;
			}
		}
	}

	printf("%.6f", finalScore / finalHakScore);
}