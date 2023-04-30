#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while(true){
        string str;
        getline(cin, str);
        if(str == "END") break;
        for(int i = str.size() - 1;i >=0;i--){
            cout<<str[i];
        }
        cout<<'\n';
    }
}