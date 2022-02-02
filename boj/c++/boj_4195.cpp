#include<bits/stdc++.h>
using namespace std;

int parent[100001];

int find(int n){
    if(parent[n]==n) return n;
    return parent[n] = find(parent[n]);
}

void uni(int a, int b){
    a = find(a);
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        int F; cin>>F;
        for(int i = 0; i<F; i++){
            string f1,f2;
            cin>>f1>>f2;

        }
    }

}