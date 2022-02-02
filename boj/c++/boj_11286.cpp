#include<iostream>
#include<queue>
#include<functional>
using namespace std;
#define ll long long

struct cmp{
    bool operator()(ll x, ll y){
        if (abs(x)==abs(y)) return x>y;
        return abs(x)>abs(y);
    }
};
int N;
priority_queue<ll,vector<ll>,cmp>pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    while(N--){
        int x;
        cin>>x;
        if(!x){
            if(pq.empty()) cout<<"0\n";
            else cout<<pq.top()<<"\n",pq.pop();
        }
        else pq.push(x);
    }
}