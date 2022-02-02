#include<iostream>
#include<map>
using namespace std;

int N,M;
map<int,int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    while(N--){
        int x; cin>>x;
        m[x]++;
    }
    cin>>M;
    while(M--){
        int x; cin>>x;
        cout<<m[x]<<" ";
    }
}