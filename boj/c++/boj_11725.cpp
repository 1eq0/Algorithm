#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N;
vector<int> v[100001];
int parent[100001];

void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int ch : v[cur]){
            if(!parent[ch]) {parent[ch] = cur; q.push(ch);}
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i = 0 ; i<N-1; i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1);

    for(int i = 2; i<=N; i++)
        cout<<parent[i]<<"\n";
}