#include<iostream>
using namespace std;

int n,m;
const int n_ = 500001;
int parent[n_];

void init(){
	for(int i = 0; i<n_; i++){
		parent[i] = -1;
	}
}

int find(int n){
	if(parent[n] == -1) return n;
	return parent[n] = find(parent[n]);
}

bool uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return false;
	if(a>b) swap(a,b);
	parent[b] = a;
	return true;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	int ans = 0;
	init();
	
	for(int i = 1; i<=m; i++){
		int a,b; cin>>a>>b;
		if(!uni(a,b)) {
			ans = i;
			break;
		}
	}
	cout<<ans<<"\n";
}