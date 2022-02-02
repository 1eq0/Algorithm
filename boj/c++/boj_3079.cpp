#include<iostream>
using namespace std;
#define ll long long

ll N,M;
int T[1000001];
ll ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i = 0; i<N; i++)
        cin>>T[i];
    
    ll low = 0, high = 1e18;
    ll mid;
    while(low<=high){
        mid = (low + high)/2;
        ll sum = 0;
        for(int i = 0; i<N; i++){
            sum += mid/T[i];
            if(sum>=M) break;
        }
        if(sum>=M){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans;
}