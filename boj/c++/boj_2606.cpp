#include<iostream>
#include<vector>
using namespace std;

vector<int> v[101];
bool visited[101];
int n,e,ans;

void DFS(int s){
    visited[s] = true;
    for(int next : v[s]){
        if(!visited[next]){
            DFS(next);
            ans++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);
    cout<<ans;
}