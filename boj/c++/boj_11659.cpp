#include<iostream>
using namespace std;

int N,M,ans;
int arr[10000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    int a,b;
    for(int i = 1; i<=N; i++)
    {
        cin>>a;
        arr[i] = arr[i-1] + a;
    }
    while(M--){
        cin>>a>>b;
        ans = arr[b]-arr[a-1];
        cout<<ans<<"\n";
    }
}