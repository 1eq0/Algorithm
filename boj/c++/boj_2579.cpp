#include<iostream>
using namespace std;
#define ll long long

int n;
ll dp[301];
ll score[301];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n; i++){
        int s;
        cin>>s;
        score[i] = s;
    }

    dp[1] = score[1];
    dp[2] = max(score[2], dp[1]+score[2]);
    for(int i = 3; i<=n; i++){
        dp[i] = max(dp[i-3]+score[i-1],dp[i-2])+score[i];
    }
    cout<<dp[n];
}