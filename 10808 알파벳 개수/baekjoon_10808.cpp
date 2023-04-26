#include <iostream>
#include <string>
using namespace std;

int x[26] = {0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string str;

    cin>>str;

    for(int i = 0,str_size = str.size();i<str_size;i++){
        x[str[i] - 'a']++;
    }

    for(int i = 0;i<26;i++){
        cout<<x[i]<<' ';
    }
}