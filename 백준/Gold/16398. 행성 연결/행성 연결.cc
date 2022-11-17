#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long

const int v_ = 1001;

struct node{
	int u,v,w;
	bool operator < (const node& a)const {
		return w < a.w;
	}
};
vector<node> edges;
int parent[v_];

int N;

int find(int n){
	if(parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

bool uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
    if (a > b) parent[a] = b;
    else parent[b] = a;
    return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			int c; cin>>c;
			if(i<j) edges.push_back({i,j,c});
		}
	}
	
	ll answer = 0;
	
	for(int i = 0; i<=N; i++)
		parent[i] = i;
		
	sort(edges.begin(), edges.end());
	
	for(auto edge : edges){
		if(uni(edge.u, edge.v)) answer += edge.w;
	}
	cout<<answer<<"\n";
}