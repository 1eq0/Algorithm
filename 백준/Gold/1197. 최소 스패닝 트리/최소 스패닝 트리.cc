#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

const int v_ = 10001;
const int e_ = 100001;
int parent[v_];
vector<pair<ll,pair<int,int>>> edges;

int V,E;

int find(int n){
	if(parent[n]==n) return n;
	return find(parent[n]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(a>b) swap(a,b);
	parent[b] = a;
}

bool isCycle(int a, int b){
	a = find(a);
	b = find(b);
	return (a==b);
}

ll solve(){
	ll answer = 0;
	for(int i = 0; i<=V; i++)
		parent[i] = i;
	for(int i = 0; i<E; i++){
		if(!isCycle(edges[i].second.first,edges[i].second.second)){
			uni(edges[i].second.first, edges[i].second.second);
			answer += edges[i].first;
		}
	}
	return answer;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>V>>E;
	for(int i = 0; i<E; i++){
		ll a,b,c; cin>>a>>b>>c;
		edges.push_back({c,{a,b}});
	}
	sort(edges.begin(),edges.end());
	cout<<solve();
}