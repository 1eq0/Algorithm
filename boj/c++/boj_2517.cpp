#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 2e6;
int n,powerN;
vector<pair<ll,int> > player; 
int t[MAX+1];

bool cmpIdx(pair<ll,int> &a, pair<ll,int> &b){
  return a.second<b.second;
}

void update(ll p){
  p = powerN + p -1;
  t[p] += 1;
  for(;p>1;p>>=1){
    t[p>>1] = t[p] + t[p^1];
  }
}

int query(int l, int r){
  int ret = 0;
  l = l + powerN - 1;
  r = r + powerN - 1;
  for(;l<=r;l>>=1,r>>=1){
    if(l&1) ret += t[l++];
    if(!(r&1)) ret += t[r--];
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>n;
  for(powerN=1;powerN<n;powerN<<=1);
  //player{ability, idx}
  for(int i = 1; i<=n; i++){
    ll a; cin>>a;
    player.push_back({a,i});
  }
  //실력값 재정의
  sort(player.begin(),player.end());
  for(int i = 0; i<n; i++){
    player[i].first = i+1;
  }

  sort(player.begin(),player.end(),cmpIdx);
  for(int i = 0; i<n; i++){
    int idx = player[i].second;
    ll ability = player[i].first;
    update(ability);
    int weak = query(1,ability-1);
    cout<<idx - weak<<"\n";
  }
}
