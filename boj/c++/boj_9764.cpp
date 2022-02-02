#include<iostream>
using namespace std;

int N;
int dp[2001][2001];

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>N;
        for(int i = 0; i<=N; i++)
        {
            for(int j = 0; j<=N; j++)
            {
                if(i==0) dp[i][j] = 1;
                if(j==0) dp[i][j] = 0;
                if(i==0&&j==0) dp[i][j] = 1;

                else
                {
                    dp[i][j] = dp[i][j-1];
                    if(i>=j) dp[i][j] = (dp[i][j-1] + dp[i-j][j-1])%100999;
                }
            }
        }

        cout<<dp[N][N]<<endl;
    }
}