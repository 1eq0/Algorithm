#include<iostream>
#include<queue>
using namespace std;
#define MAX 100000

int N, K, ans;
queue<pair<int, int>> q;
bool check[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>K;
    q.push({N,0});
    while(!q.empty()){
        int cur = q.front().first;
        ans = q.front().second;
        check[cur] = true;
        if(cur == K) break;
        q.pop();

        if(cur!=0){
            if(cur-1<=MAX && !check[cur-1]) q.push({cur-1,ans+1});
            if(cur*2<=MAX && !check[cur*2]) q.push({cur*2,ans+1});
        }
        if(cur+1<=MAX && !check[cur+1]) q.push({cur+1,ans+1});
    }
    cout<<ans;
}