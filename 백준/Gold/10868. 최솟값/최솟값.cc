#include<iostream>
using namespace std;
#define ll long long
#define INF 1000000001

const int n_ = 100001;
int tree[n_*4];
int arr[n_];
int N,M;

int init(int s, int e, int cur){
	if(s==e){
		return tree[cur] = arr[s];
	}
	int m = (s+e)/2;
	return tree[cur] = min(init(s,m,cur*2), init(m+1,e,cur*2+1));
}

int query(int cur, int s, int e, int l, int r){
	if(s>r || e<l) return INF;
	if(l<=s && e<=r) return tree[cur];
	int m = (s+e)/2;
	return min(query(cur*2,s,m,l,r),query(cur*2+1,m+1,e,l,r));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N>>M;
	for(int i = 1; i<=N; i++){
		cin>>arr[i];
	}
	init(1,N,1);
	while(M--){
		int l,r; cin>>l>>r;
		cout<<query(1,1,N,l,r)<<"\n";
	}
}