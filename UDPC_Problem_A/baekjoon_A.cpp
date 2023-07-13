#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <utility>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

int main()
{
	int N = 1000, M = 5000, tMAX = 10000;
	int i, t, a, b;
	pii tmp;
	set<pii> s;
	set<pii>::iterator it;
	vector<pii> v;

	printf("%d %d\n", N, M);

	for (i = 1; i < N; ++i) s.insert({ i, i + 1 });

	while (s.size() < M) {
		a = rand() % N + 1;
		b = rand() % N + 1;
		if (a > b) t = a, a = b, b = t;
		s.insert({ a, b });
	}

	for (it = s.begin(); it != s.end(); ++it) {
		tmp = *it;
		v.push_back(tmp);
	}

	for (i = 0; i < 3000; ++i) {
		pii& p1 = v[rand() % M];
		pii& p2 = v[rand() % M];
		tmp = p1, p1 = p2, p2 = tmp;
	}

	for (i = 0; i < v.size(); ++i) {
		t = rand() % tMAX + 1;
		printf("%d %d %d\n", v[i].fi, v[i].se, t);
	}
	return 0;
}