#include<iostream>
#include<queue>
using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int dist[1001][1001];
int box[1001][1001];
queue<pair<int,int>> q;

int M,N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>M>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>box[i][j];
            dist[i][j] = -1;
            if(box[i][j]==1){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int k = 0; k<4; k++){
            int nextX = curX + dx[k];
            int nextY = curY + dy[k];
            if(nextX<0 || nextX>=N || nextY<0 || nextY>=M) continue;
            if(box[nextX][nextY]==0 && dist[nextX][nextY] == -1){
                q.push({nextX,nextY});
                box[nextX][nextY] = 1;
                dist[nextX][nextY] = dist[curX][curY]+1;
            }
        }
    }
    int ans = -1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            ans = max(ans,dist[i][j]);
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(box[i][j]==0) ans = -1;
        }
    }
    cout<<ans;
}