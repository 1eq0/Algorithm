#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll N,M;
int arr[10000001];
int ans;

int low,high,mid;
void solve()
{
    while(low<=high){
        mid = (low+high)/2;
        ll sum = 0;
        for(int i = 0; i<N; i++){
            sum += (arr[i]-mid>0?arr[i]-mid:0);
            if (sum>=M) break;
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

     cin>>N>>M;
     for(int i = 0; i<N; i++){
        cin>>arr[i];
        high = max(high,arr[i]);
     }
    sort(arr,arr+N);
    solve();
    cout<<ans;
 }