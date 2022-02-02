#include<bits/stdc++.h>
using namespace std;

int N,M;
int arr[301][21];
int dp[301][21];
int c[301][21];

int dfs(int money, int company){
    if(company>M) return 0;
    int &res = dp[money][company];
    if(res!=-1) return res;
    res = 0;
    for(int i = 0; i<=money; i++){
        int temp = arr[i][company] + dfs(money-i,company+1);
        if(res<temp){
            res = temp;
            c[money][company] = i;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i = 1; i<=N; i++){
        int idx; cin>>idx;
        for(int j = 1; j<=M; j++){
            int comp; cin>>comp;
            arr[idx][j] = comp;
        }
    }

    for(int i = 0; i<301; i++)
        memset(dp[i],-1,sizeof(dp[i]));
        
    cout<<dfs(N,1)<<"\n";

    for(int i = 1; i<=M; i++){
        cout<<c[N][i]<<" ";
        N-=c[N][i];
    }
}