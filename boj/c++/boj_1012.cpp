#include<iostream>
using namespace std;

bool field[51][51];
bool visited[51][51];
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
int M,N;

void DFS(int x,int y){
    visited[x][y]=true;
    for(int i = 0; i<4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX<0 || nextX>=N) continue;
        if(nextY<0 || nextY>=M) continue;
        if(field[nextX][nextY] && !visited[nextX][nextY]){
            DFS(nextX,nextY);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    int component;
    while(t--){
        component = 0;
        cin>>M>>N;
        int k; cin>>k;
        while(k--){
            int x,y;
            cin>>x>>y;
            field[y][x] = 1;
        }

        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(field[i][j] && !visited[i][j]){
                    DFS(i,j);
                    component++;
                }
            }
        }

        cout<<component<<"\n";

        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                visited[i][j] = false;
                field[i][j] = 0;
            }
        }
    }

}