#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2222, M = 11111;
int n, c, m;
struct Box { int a, b, t; };
Box a[M];
int truck[N], x, v;
int ans;
int cmp(const Box& p, const Box& q) { return p.b < q.b || (p.b == q.b && p.a > q.a); }

int main()
{
	int i, j;
	cin >> n >> c >> m;
	for (i = 0; i < m; ++i) cin >> a[i].a >> a[i].b >> a[i].t;	
	sort(a, a + m, cmp);
	ans = 0;
	for (i = 0; i < m; ++i) {
		x = 0;
		for (j = a[i].a; j < a[i].b; ++j)
			if (truck[j] > x) x = truck[j];
		v = min(a[i].t, c - x);
		for (j = a[i].a; j < a[i].b; ++j) {
			truck[j] += v;
		}
		ans += v;
	}
	cout << ans << '\n';
	return 0;
}