#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
#define ll long long

struct cmp{
    bool operator()(ll x, ll y){
        return x<y;
    }
};

int n;
priority_queue<ll, vector<ll>, cmp> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    while(n--){
        ll x; cin>>x;
        if(!x){
            if(pq.empty()) cout<<"0\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else pq.push(x);
    }
}