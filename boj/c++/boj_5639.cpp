#include<iostream>
#include<vector>
using namespace std;

vector<int> nodes;

void solve(int l,int r){
    int root = nodes[l];
    int idx = l+1;
    if(l>=r) {cout<<root<<"\n"; return;}
    while(1){
        idx++;
        if(idx>r) break;
        if(root<nodes[idx]) break;
    }

    if(l<=idx-1)solve(l+1,idx-1);
    if(idx<=r) solve(idx,r);
    cout<<root<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int input;
    while(cin>>input){
        nodes.push_back(input);
    }
    solve(0, nodes.size()-1);
}