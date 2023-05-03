#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(!b) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int N,M,x,y,day = 0;
        cin>>N>>M>>x>>y;
        day = x;

        int maximum = lcm(N,M);

        while(maximum >= day) {
            int temp = day % M == 0 ? M : day % M;
            if(temp == y) break;

            day += N;
        }
        if (maximum < day) {
            cout<<"-1\n";
        }
        else {
            cout << day << '\n';
        }
    }
}