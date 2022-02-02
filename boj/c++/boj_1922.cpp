#include<bits/stdc++.h>
using namespace std;

int N,M,ans;
int parent[100001];
vector<pair<int,pair<int,int>>> e;

int find(int n){
    if(parent[n]==n) return n;
    return parent[n] = find(parent[n]);
}
bool uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    parent[b] = a;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i = 0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        e.push_back({c,{a,b}});
    }
    sort(e.begin(),e.end());
    for(int i = 1; i<=N; i++){
        parent[i]=i;
    }
    
    for(int i = 0; i<M; i++){
        int n1 = e[i].second.first;
        int n2 = e[i].second.second;
        if(uni(n1,n2)) ans+=e[i].first;
    }
    cout<<ans<<"\n";
}