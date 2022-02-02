#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int N;
ll A[2050];
ll ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>A[i];
    }

    sort(A,A+N);
    for(int i = 0; i<N; i++){
        ll num = A[i];
        int a = 0, b = N-1;
        while(1){
            ll sum = 0;
            sum = A[a] + A[b];
            if(a!=i && b!=i && a!=b)
            {            
                if (sum == num ){
                    ans++;
                    break;
                }
                if(num>=sum) a++;
                else b--;
            }
            else{
                if(b==i)b--;
                else a++;
            }
            if(a>b) break;
            
        }
    }
    cout<<ans;
}