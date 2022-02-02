#include<iostream>
using namespace std;

int N,M;
int A[1000001];
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i = 0; i<N; i++)
        cin>>A[i];
    
    int a = 0, b = 0;
    while(1){
        int sum = 0;
        for(int i = a; i<=b; i++){
            sum += A[i];
        }
        if(sum == M) ans++;
        if(b==N) break;
        else{
            if(sum<M) b++;
            else a++;
        }
    }

    cout<<ans;
}