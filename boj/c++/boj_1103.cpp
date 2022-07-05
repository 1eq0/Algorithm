#include<bits/stdc++.h>
using namespace std;

int N,M;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
char board[51][51];
bool visited[51][51];
int dp[51][51];

int solve(int x, int y){
  if(x<0||x>=N||y<0||y>=M||board[x][y]==-1) return 0;
  if(visited[x][y]){cout<<-1<<"\n"; exit(0);}
  if(dp[x][y]) return dp[x][y];
  visited[x][y] = true;
  for(int i = 0; i<4; i++){
    int nx = x + dx[i]*(board[x][y]-'0');
    int ny = y + dy[i]*(board[x][y]-'0');
    dp[x][y] = max(dp[x][y], solve(nx,ny)+1);
  }
  visited[x][y] = false;
  return dp[x][y];
}

int main(){
  cin>>N>>M;
  for(int i = 0; i<N; i++){
    string s; cin>>s;
    for(int j = 0; j<M; j++){
      if(s[j]=='H') board[i][j] = -1;
      else board[i][j] = s[j];
    }
  }
  cout<<solve(0,0)<<"\n";
}
