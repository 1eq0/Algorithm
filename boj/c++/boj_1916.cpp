#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
#define ll long long

const ll n_ = 1020, inf = 1e18;

ll N, M;
ll start,fin;

vector<pair<ll,ll>>v[n_];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
ll dist[n_];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    fill(dist,dist+N+1,inf);
    while(M--){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }

    cin>>start>>fin;
    dist[start] = 0;
    pq.push({0,start});

    while(pq.size()){  
        auto cur = pq.top(); pq.pop(); 
        if(dist[cur.second]<cur.first) continue;
        for(auto next : v[cur.second]){
            if(dist[next.first]<=cur.first+next.second) continue;
            dist[next.first]=cur.first+next.second;
            pq.push({dist[next.first],next.first});
        }
    }

    cout<<dist[fin];
}