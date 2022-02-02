#include<iostream>
using namespace std;

int N,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    while(N--){
        int num; cin>>num;
        bool isPrime = true;
        for(int i = 2; i*i<=num; i++){
            if(num%i==0){
                isPrime = false;
                break;
            }
        }
        if(num!=1 && isPrime) ans++;
    }
    cout<<ans;
}