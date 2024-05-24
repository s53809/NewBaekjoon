#include <iostream>
#define MOD 1000000000
using namespace std;

long long dp[500001] = { 1, 2, 4, 6 };
long long bpart(int n)
{
    if (dp[n]) return dp[n];
    return dp[n] = (bpart(n - 1) + bpart(n >> 1)) % MOD;
}

int main()
{
    int n;
    cin >> n;
    cout << bpart(n >> 1);
    return 0;
}