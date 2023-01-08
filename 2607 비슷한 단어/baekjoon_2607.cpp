#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string word;
string simWord;
vector<int> wordCount(26, 0);

void InitWordCount() {
	fill(wordCount.begin(), wordCount.end(), 0);
	for (int i = 0, word_size = word.size(); i < word_size; i++) {
		wordCount[word[i] - 'A']++;
	}
}

bool IsSimilarWord(string str) {
	InitWordCount();
	bool isCountEqual = false;
	if (abs((int)(str.size() - word.size())) >= 2) return false;
	int countWrongWord = 0;
	for (int i = 0, word_count = str.size(); i < word_count; i++) {
		if (wordCount[str[i] - 'A'] == 0 && countWrongWord != 0) return false;
		else if (wordCount[str[i] - 'A'] == 0 && countWrongWord == 0) countWrongWord++;
		else if (wordCount[str[i] - 'A'] != 0) wordCount[str[i] - 'A']--;
	}
	int mazimak = 0;
	for (int i = 0, word_size = word.size(); i < word_size; i++) {
		if (wordCount[i] != 0) mazimak++;
	}
	if (mazimak > 1) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int answer = 0;
	cin >> N;
	cin >> word;
	InitWordCount();
	for (int i = 0; i < N - 1; i++) {
		cin >> simWord;
		if (IsSimilarWord(simWord)) { answer++; }
	}
	cout << answer;
}