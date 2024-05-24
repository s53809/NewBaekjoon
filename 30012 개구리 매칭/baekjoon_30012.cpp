#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int s, n;
    cin >> s >> n;

    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }

    int k, l;
    cin >> k >> l;

    int min_i = 0;
    int min_v = 10000 * 100001;

    for (int i = 0; i < n; ++i) {
        int d = abs(e[i] - s);
        int t = (k * 2 - d >= 0) ? (k * 2 - d) : ((d - k * 2) * l);

        if (min_v > t) {
            min_v = t;
            min_i = i + 1;
        }
    }

    cout << min_v << " " << min_i << '\n';

    return 0;
}