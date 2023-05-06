#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    int N;
    cin>>N;
    string comp = "codeforces";
    while(N--){
        string str;
        cin>>str;
        int ans = 0;
        for(int i = 0;i<10;i++){
            if(comp[i] != str[i]) ans++;
        }
        cout<<ans<<'\n';
    }
}