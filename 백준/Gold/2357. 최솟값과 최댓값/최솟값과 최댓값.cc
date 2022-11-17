#include<iostream>
using namespace std;
#define ll long long
#define INF 1000000001
#define pii pair<int,int>

int N,M;
const int n_ = 100001;
int arr[n_];
pii tree[n_*4];

pii init(int s, int e, int cur){
	if(s==e){
		tree[cur].first = arr[s];
		tree[cur].second = arr[s];
		
		return tree[cur];
	}
	int mid = (s+e)/2;
	
	pii a = init(s,mid,cur*2);
	pii b = init(mid+1,e,cur*2+1);
	
	tree[cur].first = (a.first<b.first) ? a.first : b.first;
	tree[cur].second = (a.second>b.second) ? a.second : b.second;
	
	return tree[cur];
}

pii query(int cur, int s, int e, int l, int r){
	if(s>r || e<l) return {INF,0};
	if(l<=s && e<=r) return tree[cur];
	
	int mid = (s+e)/2;
	pii left,right;
	
	left = query(cur*2, s, mid, l, r);
	right = query(cur*2+1, mid+1, e, l, r);
	
	int min = (left.first < right.first) ? left.first : right.first;
	int max = (left.second > right.second) ? left.second : right.second;
	
	return {min,max};
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
		pii minmax = query(1,1,N,l,r);
		cout<<minmax.first<<" "<<minmax.second<<"\n";
	}
}