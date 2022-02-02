#include<iostream>
using namespace std;
#define MOD 1000000007

int N;
long long C[1520][1520];
int one,five;
long long ans;

void combination(){
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<=i; j++){
            if(j==0 || i==j) C[i][j] = 1;
            else{
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
            }
        }
    }
}

void solve(){
    for(one = N-1; one>=0; one--){
        five = N-1-one;
        if((one + (five+1)*5)%3==0){
            ans += C[N-1][one];
            ans %= MOD;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>N;
    combination();
    solve();

    cout<<ans;
}