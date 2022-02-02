#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
#define ll long long

ll N;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
vector<pair<ll,ll>>v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>N;
    for(int i = 0; i<N; i++){
        ll a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    std::sort(v.begin(),v.end());
    
    pq.push({v[0].second,v[0].first});
    for(int i = 1; i<N; i++){
        auto cur = pq.top();
        if(cur.first<=v[i].first) pq.pop();
        pq.push({v[i].second,v[i].first});
    }
    cout<<pq.size();
}