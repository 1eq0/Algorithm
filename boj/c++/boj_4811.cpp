#include<bits/stdc++.h>
using namespace std;
#define ll long long

int N;
ll dp[35][35];

ll dfs(int W, int H){
    if(dp[W][H]) return dp[W][H];
    if(W==0) return 1;
    if(H>0) dp[W][H] += dfs(W,H-1)+dfs(W-1,H+1);
    else dp[W][H] += dfs(W-1,H+1);
    return dp[W][H];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1){
        cin>>N; if(!N) break;

        for(int i = 0; i<35; i++)
            memset(dp[i],0,sizeof(dp[i]));
        cout<<dfs(N-1,1)<<"\n";
    }
}