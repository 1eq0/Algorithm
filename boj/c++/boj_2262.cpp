#include<iostream>
#define MAX 257
using namespace std;

int n;
int player[MAX];
int dp[MAX][MAX]; //dp[i][j] : iºÎÅÍ j±îÁö ÆÀ Â®À»¶§ ·©Å·Â÷ÀÌ ÇÕ

int diff(int i, int j, int k)
{
    int ret = player;
    if(ret > 0) return ret;
    else return -ret;
}

int main()
{
    cin>>n;
    for(int i = 1; i<=n; i++)
        cin>>player[i];
    
    for(int diagonal = 1; diagonal<=n-1; diagonal++)
    {
        for(int i = 1; i<=n-diagonal; i++)
        {
            int j = i + diagonal;
            for(int k = i; k<=j-1; k++)
            {
                if(k==i) dp[i][j] = dp[i][k] + dp[k+1][j] + diff(i,j,k);
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + diff(i,j,k));
            }
        }
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
            cout<<dp[i][j];
        cout<<endl;
    }
    cout<<dp[1][n];
}