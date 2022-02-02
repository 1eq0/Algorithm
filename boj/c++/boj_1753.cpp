#include<iostream>
#include<functional>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long

const ll n_ = 200001, inf = 1e18;

ll V,E,K,dist[n_];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<> >pq;
vector<pair<ll,ll>> v[n_];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>V>>E>>K;
    while(E--){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }

    fill(dist,dist+V+1,inf); //모든 정점까지 거리를 무한대로 초기화
    dist[K] = 0;
    pq.push({0,K});

    while(pq.size()){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.second]<cur.first) continue;
        for(auto next : v[cur.second]){
            if(dist[next.first]<=cur.first+next.second) continue;
            dist[next.first] = cur.first + next.second;
            pq.push({dist[next.first],next.first});
        }
    }

    for(int i = 1; i<=V; i++){
        if(dist[i]==inf) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
}