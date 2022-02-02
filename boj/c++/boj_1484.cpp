#include<iostream>
using namespace std;
#define ll long long

ll G;
ll arr[100001];

ll a,b,cnt;
void solve(){
    a=1;b=1;
    while(1){
        ll diff = arr[b] - arr[a];
        if(diff == G) {cout<<b<<"\n";cnt++;}
        if(b>=100000) break;
        if(diff<G) b++;
        else a++;
    }
    if(!cnt) cout<<(-1)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(ll i = 0; i<=100000; i++)
        arr[i] = i*i;
    cin>>G;
    solve();
}