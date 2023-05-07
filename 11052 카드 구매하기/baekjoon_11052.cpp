#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> x;
vector<int> dp;

int value(int num){
    if(dp[num] != -1) return dp[num];
    int maxNum = x[num];
    for(int i = 1;i<=num / 2;i++){
        maxNum = max(maxNum, value(num - i) + value(i));
    }
    dp[num] = maxNum;
    return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>N;
    x.resize(N + 1);
    dp.resize(N + 1);
    for(int i = 1; i <= N; i++) {
        cin>>x[i];
        dp[i] = -1;
    }
    dp[N] = -1;

    cout<<value(N);
}