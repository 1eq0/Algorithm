#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int l;
ll dp[5010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    dp[1]=0; dp[0]=dp[2]=1;
    for(int i = 3; i<=5000; i++){
        if(i%2!=0) {continue;}
        for(int j = 2; j<=i; j++){
            dp[i]+=dp[j-2]*dp[i-j];
            dp[i]%=MOD;
        }
    }
    while(t--){
        cin>>l;
        cout<<dp[l]<<"\n";
    }
}