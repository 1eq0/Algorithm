#include<iostream>
using namespace std;

int board[1001][1001];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%1d",&board[i][j]);
    for(int i = 1; i<n; i++) //0부터하게되면 index가 -1인 곳을 방문하게 되므로 주의
    {   
        for(int j = 1; j<m; j++)
        {
            if(board[i][j]!=0) board[i][j] += min(board[i][j-1],min(board[i-1][j-1],board[i-1][j]));
        }
    }
    int size = 0;
    for(int i = 0 ; i<n; i++)
    {   
        for(int j = 0; j<m; j++)
        {
            size = max(size, board[i][j]);
        }
    }
    cout<<size*size;
}