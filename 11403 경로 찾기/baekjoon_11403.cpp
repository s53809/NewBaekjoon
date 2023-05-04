#include <iostream>
#include <algorithm>
using namespace std;

int dist[101][101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin>>N;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>dist[i][j];
            if(dist[i][j] == 0) { dist[i][j] = 1e9; }
        }
    }

    for(int k = 0;k < N;k++){
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(dist[i][j] == 1e9) cout<<0<<' ';
            else cout<<1<<' ';
        }
        cout<<'\n';
    }
}