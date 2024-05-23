#include<iostream>
using namespace std;
long long int N[101] = { 0,1,1,1,2,2 };
long long int DP(long long int n) {


    if (N[n] != -1) {
        return N[n];
    }
    else {

        N[n] = DP(n - 2) + DP(n - 3);
        return N[n];
    }

}
int main() {
    int T;
    cin >> T;
    for (int i = 6; i < 101; i++) {
        N[i] = -1;
    }
    DP(100);
    for (int i = 0; i < T; i++) {
        long long int n;
        cin >> n;
        cout << N[n] << "\n";
    }

}