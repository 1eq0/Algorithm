#include<iostream>
#include<vector>
using namespace std;
#define ll long long

int N,M;
const int n_ = 501, inf = 1e9;
vector<pair<int,int>> adj[n_];
ll dist[n_];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>N>>M;
    for(int i = 0; i<M; i++){
        int A,B,C;
        cin>>A>>B>>C;
        adj[A].push_back({B,C});
    }
    
    bool nCycle = false;
    fill(dist+2,dist+N+1,inf);

    for(int i = 1; i<=N; i++){
        for(int from = 1; from<=N; from++){
            if(dist[from] == inf) continue; //이어지지 않은 정점 패스
            for(auto a : adj[from]){
                int to = a.first;
                int cost = a.second;
                if(dist[to]>dist[from]+cost){
                    if(i==N) nCycle = true;
                    dist[to]=dist[from]+cost;
                }
            }
        }
    }

    if(nCycle) cout<<-1;
    else{
        for(int i = 2; i<=N; i++)
        {
            if(dist[i]==inf)cout<<"-1\n";
            else cout<<dist[i]<<"\n";
        }
    }
}