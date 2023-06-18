#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> x(1000000);

    if (N == 1) {
        cout << "1";
        return 0;
    }
    else if (N == 2) {
        cout << "10";
        return 0;
    }

    x[0] = 0;
    x[1] = 1;
    x[2] = 2;

    for (int i = 3; x[i - 1] <= N; i++) {
        x[i] = x[i - 1] + x[i - 2] + 1;
    }

    string ans = "";

    int cnt = 0;

    for (; N > 2;) {
        cnt++;
        int i = 0;
        for (; x[i] < N; i++) {}
        N -= (x[i - 1] + 1);
        int temp = i;
        ans += "10";
        for (i = 0; x[i] < N; i++) {}
        for (int j = 0; j < temp - i - 2; j++) ans += "0";
        if (N == 2) ans += "10";
        else if (N == 1) ans += "1";
    }

    cout << ans;

    return 0;
}