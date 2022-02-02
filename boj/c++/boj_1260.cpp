#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long

ll N,M,V;
vector<ll> v[1001];
bool checked[1001];

void dfs(ll x){
    checked[x] = true;
    cout<<x<<" ";
    for(ll next : v[x]){
        if(checked[next]) continue;
        dfs(next);
    }
}
void bfs(ll x){
    queue<ll>q;
    q.push(x);
    checked[x] = true;
    while(!q.empty()){
        ll cur = q.front();
        cout<<cur<<" ";
        q.pop();
        for(ll next : v[cur]){
            if(checked[next]) continue;
            q.push(next);
            checked[next] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>V;
    for(int i = 0; i<M; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i<=1000; i++){
        for(int j = 0; j<v[i].size(); j++){
            sort(v[i].begin(),v[i].end());
        }
    }
    memset(checked,false,sizeof(checked));
    dfs(V);
    cout<<"\n";
    memset(checked,false,sizeof(checked));
    bfs(V);
}