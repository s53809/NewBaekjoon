#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int x[501][501];
bool visited[501][501] = {false,};
int d_x[] = {0,0,-1,1};
int d_y[] = {-1,1,0,0};

int ex[4][4] = {
        {0, 0, 0, 1},
        {0, 1, 2, 1},
        {0, 0, 0, -1},
        {0, -1, 0, 1}
};
int ey[4][4] = {
        {0, 1, 2, 1},
        {0, 0, 0, 1},
        {0, 1, 2, 1},
        {0, 1, 1, 1}
};
int maxNum = 0;

void DFS(int posX, int posY, int num, int sum) {
    if(num == 4) {
        maxNum = max(maxNum, sum);
        return;
    }

    for(int i = 0;i<4;i++) {
        int dir_x = posX + d_x[i];
        int dir_y = posY + d_y[i];

        if(0 <= dir_x && dir_x < M && 0 <= dir_y && dir_y < N) {
            if(visited[dir_y][dir_x]) { continue; }
            visited[dir_y][dir_x] = true;
            DFS(dir_x, dir_y, num + 1, sum + x[dir_y][dir_x]);
            visited[dir_y][dir_x] = false;
        }
    }
}

void PoQPoQ(int xPos, int yPos){

    for(int i=0; i<4; i++){

        bool isOut = false;
        int sum_value = 0;

        for(int j=0; j<4; j++){
            int dir_x = xPos + ex[i][j];
            int dir_y = yPos + ey[i][j];

            if(dir_x < 0 || dir_x >= M || dir_y < 0 || dir_y >= N) {
                isOut = true;
                break;
            }
            else {
                sum_value += x[dir_y][dir_x];
            }
        }
        if(!isOut) {
            maxNum = max(maxNum, sum_value);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>N>>M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin>>x[i][j];
            visited[i][j] = false;
        }
    }

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            visited[i][j] = true;
            DFS(j,i,1,x[i][j]);
            visited[i][j] = false;

            PoQPoQ(j,i);
        }
    }

    cout<<maxNum;
}