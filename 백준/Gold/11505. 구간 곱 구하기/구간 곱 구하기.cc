#include<iostream>
using namespace std;
#define ll long long
#define MOD 1000000007

const int n_ = 1000001;
int N,M,K;
ll tree[n_*4];
ll arr[n_];

ll init(int s, int e, int cur){
	if(s==e){
		return tree[cur] = arr[s];
	}
	int m = (s+e)/2;
	return tree[cur] = (init(s,m,cur*2)%MOD) * (init(m+1,e,cur*2+1) % MOD);
}

ll update(int s, int e, int cur, int target, ll val){
	if(target<s || target>e) return tree[cur];
	if(s==e) return tree[cur] = val;
	int m = (s+e)/2;
	return tree[cur] = (update(s,m,cur*2,target,val)%MOD) * (update(m+1,e,cur*2+1,target,val)%MOD);
}

ll query(int cur, int s, int e, int l, int r){
	if(s>r || e<l) return 1;
	if(l<=s && e<=r) return tree[cur];
	int m = (s+e)/2;
	return (query(cur*2,s,m,l,r)%MOD) * (query(cur*2+1,m+1,e,l,r)%MOD);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N>>M>>K;
	for(int i = 1; i<=N; i++)
		cin>>arr[i];
		
	init(1,N,1);
	
	for(int i = 0; i<M+K; i++){
		int a,b,c; cin>>a>>b>>c;
		if(a == 1) update(1,N,1,b,c);
		else cout<<query(1,1,N,b,c)%MOD<<"\n";
	}
}