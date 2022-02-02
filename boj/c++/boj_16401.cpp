#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int N,M;
int L[10000001];
int snack[10000001];
int ans;
ll sum;

bool cmp(int a, int b){
    return a>b;
}

void solve(){
    ll high = L[N-1], low = 1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        sum = 0;
        for(int i = 0; i<N; i++)
        {    
            sum += L[i]/mid;
            if(sum>=M) break;
        }

        if(sum>=M){
            low = mid+1;
            ans = mid;
        }
        else{
            high = mid-1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>M>>N;
    for(int i = 0; i<N; i++)   
        cin>>L[i];
    
    sort(L,L+N);
    
    solve();
    cout<<ans;
}