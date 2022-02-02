#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int T,N,M;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>T;
    while(T--){
        cin>>N>>M;
        queue<pair<int,int>> q;
        vector<int> v;
        for(int i = 0; i<N; i++)
        {
            int a;
            cin>>a;
            q.push({i,a});
            v.push_back(a);
        }
        sort(v.begin(),v.end(),cmp);
        int ans = 0;
        while(!q.empty()){
            if(v.front() > q.front().second){
                auto tmp = q.front();
                q.pop();
                q.push({tmp.first,tmp.second});
            }
            else{
                ans++;
                if(q.front().first == M){
                    cout<< ans <<"\n";
                    break;
                }
                q.pop();
                v.erase(v.begin());
            }
        }

    }
}