#include<bits/stdc++.h>
using namespace std;

int N,K,ans;
int arr[200010];
int a[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>K;
    for(int i = 0; i<N; i++)
        cin>>arr[i];
    
    int l=0,r=0;
    while(1){
        a[arr[r]]++;
        if(a[arr[r]]>K){
            ans = max(ans,r-l);
            memset(a,0,sizeof(int)*100001);
            l = r;
        }
        else r++;
        if(r>=N) {ans = max(ans,r-l);break;}
    }
    cout<<ans;
}