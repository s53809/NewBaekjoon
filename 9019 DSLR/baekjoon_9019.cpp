#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int A,B;
bool visited[10000];

int D(int num) {
    return (num * 2) % 10000;
}

int S(int num) {
    return num - 1 < 0 ? 9999 : num - 1;
}

int L(int num) {
    return (num % 1000) * 10 + (num / 1000);
}

int R(int num){
    return (num / 10) + (num % 10) * 1000;
}

void BFS(){
    queue<pair<int, string>> qu;
    qu.push({A,""});
    visited[A] = true;
    while(!qu.empty()){
        pair<int, string> dist = qu.front();
        qu.pop();

        if(dist.first == B){
            cout<<dist.second<<'\n';
            break;
        }

        if(!visited[D(dist.first)]){
            visited[D(dist.first)] = true;
            qu.push({D(dist.first),dist.second + "D"});
        }
        if(!visited[S(dist.first)]){
            visited[S(dist.first)] = true;
            qu.push({S(dist.first), dist.second + "S"});
        }
        if(!visited[L(dist.first)]){
            visited[L(dist.first)] = true;
            qu.push({L(dist.first),dist.second + "L"});
        }
        if(!visited[R(dist.first)]){
            visited[R(dist.first)] = true;
            qu.push({R(dist.first), dist.second + "R"});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        cin>>A>>B;
        fill(visited, visited + 10000, false);
        BFS();
    }
}