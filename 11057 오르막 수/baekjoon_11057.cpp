#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;

int upSort(int num, int startNum){
    if(dp[num][startNum] != -1) return dp[num][startNum];
    if(num == 1) return 1;
    int hap = 0;
    for(int i = startNum;i <= 9;i++){
        hap += upSort(num - 1, i);
    }
    dp[num][startNum] = hap % 10007;
    return hap % 10007;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin>>N;
    dp.resize(N+1, vector<int>(10, -1));
    int hap = 0;
    for(int i = 0;i<=9;i++){
        hap += upSort(N,i);
    }
    cout<<hap % 10007;
}