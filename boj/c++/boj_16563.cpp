#include<iostream>
#include<vector>
using namespace std;
#define ll long long

const ll MAX = 5000000;

ll arr[MAX+1];
vector<bool> isPrime(MAX+1, true);

void solve(){
    isPrime[0]=isPrime[1]=false;
    for(ll i = 2; i<=MAX; i++){
        if(isPrime[i]){
            arr[i] = i;
            for(ll j = i*i; j<=MAX; j+=i){
                if(isPrime[j]) arr[j] = i;
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin>>N;

    solve();

    while(N--){
        ll num; cin>>num;
        while(num>1){
            cout<<arr[num]<<" ";
            num/=arr[num];
        }
        cout<<"\n";
    }
}