#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
vector<int> AB;
vector<int> CD;

int n;
ll ans;

int main() {
  ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

  cin>>n;
  for(int i = 0; i<n; i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    A.push_back(a);
    B.push_back(b);
    C.push_back(c);
    D.push_back(d);
  }

  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      AB.push_back(A[i]+B[j]); //a+b
      CD.push_back((C[i]+D[j])*-1); //-(c+d)
    }
  }

  sort(AB.begin(),AB.end());
  sort(CD.begin(),CD.end());

  ll size = AB.size();
  for(ll i = 0; i<size; i++){
    ll lower = lower_bound(CD.begin(),CD.end(),AB[i])-CD.begin();    
    ll upper = upper_bound(CD.begin(),CD.end(),AB[i])-CD.begin();
    ans += (upper-lower);
  }
  cout<<ans;
}
