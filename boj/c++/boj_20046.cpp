#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

int n,m;
const int n_ = 1001, inf = 1e9;
const int dx[4] = {0,1,-1,0};
const int dy[4] = {1,0,0,-1};
int board[n_][n_];
int dist[n_][n_];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int a; cin>>a;
            board[i][j] = a;
        }
    }

    fill(&dist[0][0],&dist[n_-1][n_],inf);
    dist[0][0] = board[0][0];
    pq.push({dist[0][0],{0,0}});

    int size = n*m;

    while(size--){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.second.first][cur.second.second]<cur.first) continue;
        if(board[cur.second.first][cur.second.second]==-1)continue;
        //cur.first : curdist
        //cur.second.first : x, cur.second.second : y
        for(int k = 0; k<4; k++){
            int nextX = cur.second.first + dx[k];
            int nextY = cur.second.second + dy[k];
            if(nextX<0 || n<=nextX || nextY<0 || m<=nextY) continue;
            if(board[nextX][nextY]==-1) continue;
            if(dist[nextX][nextY]<=board[nextX][nextY]+cur.first) continue;
            dist[nextX][nextY]=board[nextX][nextY]+cur.first;
            pq.push({dist[nextX][nextY],{nextX,nextY}});
        }
    }
    
    if(dist[n-1][m-1]==inf)cout<<-1;
    else cout<<dist[n-1][m-1];
}