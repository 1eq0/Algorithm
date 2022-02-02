#include<iostream>
#define MAX 501
using namespace std;

int M, N;

int board[MAX][MAX];
int ans[MAX][MAX];

const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};

void check(int y, int x){
    if (y==M-1 && x==N-1) return;
    
    for(int idx = 0; idx<4; idx++)
        if(board[y][x]>board[y+dy[idx]][x+dx[idx]]){
            ans[y+dy[idx]][x+dx[idx]]++;
            check(y+dy[idx],x+dx[idx]);
        }
}

int main()
{
    cin>>M>>N;
    for(int i = 0; i<M; i++)
        for(int j = 0; j<M; j++)
            cin>>board[i][j];

    
    check(0,0); 
    for(int i = 0; i<M; i++)
        {for(int j = 0; j<N; j++)
            cout<<ans[i][j];
        cout<<endl;}
    //cout<<ans[M-1][N-1];
}