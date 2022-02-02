#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N,M;
vector<int>v[200001];
int ans[200001];
queue<int> q,tmp;
int check[2000001];

void solve(){
    int t = 0;
    while(!tmp.empty()){
        while(!tmp.empty()){
            int cur = tmp.front(); tmp.pop();
            q.push(cur);
        }
        int size = q.size();
        while(size--){
            int cur = q.front(); q.pop();
            //시간기록 : check >= v[i].size / 2
            if(check[cur]*2>=v[cur].size()) ans[cur] = t;
            q.push(cur);
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            //방문체크
            if(ans[cur]!=-1)
            {
                for(int n:v[cur]){
                    check[n]++;
                    if(ans[n]==-1)tmp.push(n);
                }
            }
        }
        t++;
    } 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i = 1; i<=N; i++)
    {
        while(1){
            int a; cin>>a;
            if(a==0) break;
            v[i].push_back(a);
        }
        ans[i] = -1;
    }
    
    cin>>M;
    for(int i = 0; i<M ;i++){
        int a; cin>>a;
        tmp.push(a);
        ans[a] = 0;
    }

    solve();
    for(int i = 1; i<=N; i++){
        cout<<ans[i]<<" ";
    }
}