#include<iostream>
#include<vector>
using namespace std;
#define ll long long

ll N;
const ll MAX = 1e12;

vector<ll> primes;

void prime(ll x){
    for(ll i = 2; i*i<=x; i++){
        if(x%i) continue;
        while(x%i==0){
            primes.push_back(i);
            x/=i;
        }
    }
    if(x!=1) primes.push_back(x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    prime(N);

    ll size = primes.size();
    if(size == 1) cout<<-1;
    else{
        if(size%2==0){
            for(ll i = 0; i<size; i+=2){
                cout<<primes[i]*primes[i+1]<<" ";
            }
        }
        else{
            ll i = 0;
            for(i = 0; i<size-3; i+=2){
                cout<<primes[i]*primes[i+1]<<" ";
            }
            cout<<primes[i]*primes[i+1]*primes[i+2];
        }
    }
}
