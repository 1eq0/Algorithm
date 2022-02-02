#include<iostream>
#include<queue>
using namespace std;
#define ll long long

int A,B;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>A>>B;
    bool exans = false;

    queue<pair<ll,ll>> q;
    q.push({A,0});

    while(!q.empty()){

        bool check = false;
        ll cur = q.front().first; 
        ll ans = q.front().second;
        if(cur == B) {exans = true; break;}
        q.pop();

        ll n1 = cur*2;
        ll n2 = cur*10+1;

        if(n1<=B) q.push({n1,ans+1});
        if(n2<=B) q.push({n2,ans+1});
    }
    if(!exans) cout<<-1;
    else cout<<q.front().second+1;
}