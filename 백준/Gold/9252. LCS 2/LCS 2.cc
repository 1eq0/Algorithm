#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string a,b,ans;
const int n_ = 1001;
int dp[n_][n_];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	int len1 = a.size(), len2 = b.size();
	
	for(int i = 1; i<=len1; i++){
		for(int j = 1; j<=len2; j++){
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[len1][len2]<<"\n";
	
	while(dp[len1][len2]){
		if(dp[len1][len2] == dp[len1][len2-1]) len2--;
		else if(dp[len1][len2] == dp[len1-1][len2]) len1--;
		else if(dp[len1][len2] - 1 == dp[len1-1][len2-1]){
			ans += a[--len1];
			len2--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}