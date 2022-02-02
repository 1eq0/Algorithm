#include<iostream>
using namespace std;

int N,K;
int dp[11][11];

void solve(){
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i<11; i++){
        for(int j = 0; j<11; j++){
            if(j==0 || i==j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>N>>K;
    solve();

    cout<<dp[N][K];
}