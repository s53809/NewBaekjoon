#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int min01 = 1e9;
        int min10 = 1e9;
        int ans = 1e9;
        for(int i = 0;i<N;i++){
            int a;
            string b;
            cin>>a>>b;
            if(b == "01") min01 = min(min01, a);
            if(b == "10") min10 = min(min10, a);
            if(b == "11") ans = min(ans, a);
        }
        ans = min(ans, min01 + min10);
        if(ans == 1e9) cout<<"-1\n";
        else cout<<ans<<'\n';
    }
}