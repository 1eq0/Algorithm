#include<iostream>
using namespace std;

int N;
int triangle[501][501];
int dp[501][501];

int main()
{
    cin>>N;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<=i; j++)
            cin>>triangle[i][j];
    }

    dp[0][0] = triangle[0][0];
    for(int i = 1; i<N; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            if(j==0) dp[i][j] = dp[i-1][j] + triangle[i][j];
            else dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            if(j!=0||j!=i)
                dp[i][j] = max(dp[i][j],dp[i-1][j]+triangle[i][j]);
        }
    }
    
    int ans = dp[N-1][0];
    for(int i = 1; i<N; i++)
        ans = max(ans, dp[N-1][i]);

    cout<<ans;
}