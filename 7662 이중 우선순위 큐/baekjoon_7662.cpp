#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        multiset<int> multiQu;
        for(int i = 0;i<N;i++){
            char ch;
            int inputN;
            cin>>ch>>inputN;
            if(ch == 'I') multiQu.insert(inputN);
            else {
                if(multiQu.empty()) continue;
                if (inputN == -1) multiQu.erase(multiQu.begin());
                else {
                    auto iter = multiQu.end();
                    iter--;
                    multiQu.erase(iter);
                }
            }
        }
        if(multiQu.empty()) cout<<"EMPTY\n";
        else {
            auto iter = multiQu.end();
            iter--;
            cout << *iter << ' ' << *multiQu.begin() << '\n';
        }
    }
}