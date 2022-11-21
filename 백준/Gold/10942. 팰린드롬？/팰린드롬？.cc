#include<iostream>
using namespace std;

int N,M;
const int n_ = 2001;
int a[n_];
int dp[n_][n_];

int solve(int i, int j){
	
	if(dp[i][j] != -1) return dp[i][j];
	
	if(i==j) return dp[i][j] = true;
	if(i+1 == j) return dp[i][j] = (a[i] == a[j]);
	if(a[i] == a[j] && solve(i+1,j-1) == 1) return dp[i][j] = true;
	return dp[i][j] = false;	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N;
	for(int i = 1; i<=N; i++){
		cin>>a[i];
	}
	
	for(int i = 0; i<n_; i++){
		for(int j = 0; j<n_; j++){
			dp[i][j] = -1;
		}
	}
	
	cin>>M;
	while(M--){
		int s,e; cin>>s>>e;
		cout<<solve(s,e)<<"\n";
	}
}