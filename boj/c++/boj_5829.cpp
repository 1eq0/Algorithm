#include<iostream>
#include<vector>
using namespace std;

int N,M,K;
vector<pair<int,int>> port[1001];

void solve_L(int p, int d){
    if(d==0) return;

    int next = port[p].front().first;
}
void solve_R(int p, int d){
    if(d==0) return;

    int next = port[p].front().second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>K;

    for(int i = 1; i<=N; i++){
        int L,R;
        cin>>L>>R;
        port[i].push_back(make_pair(L,R));
    }

    int d;
    for(int i = 0; i<M; i++){
        char dir; cin>>dir;
        if(dir=='L') d++;
        else d--;
    }

    if(d>0) solve_L(1,d,);
    else solve_R(1,d>0 ? d : d*(-1),);
}