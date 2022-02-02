#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

vector<pair<int,int>> edge[10001];

int n,x;
int sum = 0;
bool visited[10001];

void dfs(int start,int w){
    if(visited[start]) return;
    visited[start] = true;

    if(sum<w){
        sum = w;
        x = start;
    }

    for(auto next : edge[start]){
            dfs(next.first,w+next.second);
    }
}

int main(){
    cin>>n;
    for(int i = 0; i<n-1; i++){
        int p,c,w;
        cin>>p>>c>>w;
        edge[p].push_back(make_pair(c,w));
        edge[c].push_back(make_pair(p,w));
    }
    dfs(1,0);
    memset(visited,false,sizeof(visited));sum = 0;
    dfs(x,0);
    cout<<sum;
}