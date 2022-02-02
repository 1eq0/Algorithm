#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<int> V[1001];
bool visited[1001];

void DFS(int start){
    visited[start] = true;
    for(int next : V[start]){
        if(visited[next]) continue;
        visited[next] = true;
        DFS(next);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    while(M--){
        int u,v;
        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    int component = 0;
    for(int i = 1; i<=N; i++){
        if(!visited[i]){
            DFS(i);
            component++;
        }
    }
    cout<<component;
}