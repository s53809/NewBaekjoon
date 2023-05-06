#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        int ans = 0;
        int stac = 0;

        for(int i = 0;i<N;i++){
            int temp;
            cin>>temp;
            if(temp == 0) stac++;
            else if(temp == 1) { ans = max(ans, stac); stac = 0; }
        }

        ans = max(ans, stac);

        cout<<ans<<'\n';
    }
}