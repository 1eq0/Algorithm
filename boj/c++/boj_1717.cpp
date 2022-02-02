#include<bits/stdc++.h>
using namespace std;

int n,m;
int parent[1000001];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    parent[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i<=n; i++){
        parent[i] = i;
    }

    while(m--){
        int cmd,a,b;
        cin>>cmd>>a>>b;

        if(cmd == 0) uni(a,b);
        else{
            if(find(a)==find(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}