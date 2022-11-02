#include <iostream>
#include <algorithm>
using namespace std;

const int n_ = 101;
const int k_ = 100001;
int dp[n_][k_]; 
/*
dp[i][j] : 가방 용량이 j이고, 1~i번째 물건까지 살펴봤을 때 가치의 최댓값 
dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])
> dp[i-1][j] : 용량 j인 가방에 i번째 물건을 넣지 않았을 때
> dp[i-1][j-w[i]] + v[i] : i번째 물건을 넣었을 때
	- 물건 넣을 만큼 공간을 확보 : j-w[i] 
*/
int W[n_]; 
int V[n_];

int N,K;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N>>K;
	for(int i = 1; i<=N; i++){
		cin>>W[i]>>V[i];
	}
	
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=K; j++){
			//i번째 물건을 넣을 수 있다면 
			if(W[i]<=j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
			else dp[i][j] = dp[i-1][j];
		}
	} 
	
	cout<<dp[N][K];
}