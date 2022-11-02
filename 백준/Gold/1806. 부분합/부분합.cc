#include <iostream>
using namespace std;
#define ll long long

const int n_ = 100001;
ll sum[n_];
int n[n_];

int N,S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N>>S;
	for(int i = 1; i<=N; i++){
		cin>>n[i];
		sum[i] = sum[i-1]+n[i];
	}

	int s = 1, e = 1; int ans = 1e9;
	while(s<=e && e<=N){
		ll result = sum[e]-sum[s-1];
		if(result>=S) ans = min(ans, e-s+1);
		if(result>S) s++;
		else e++;
	}
	if(ans == 1e9) ans = 0;
	cout<<ans;		
}