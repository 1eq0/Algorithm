#include<iostream>
#include<vector>
using namespace std;

struct TREENODE{
    int parent = -1;
    vector<int> children;
};

int N,K,root,ans;
struct TREENODE tree[51];

void solve(int r){
    if(r==K){
        if(tree[tree[r].parent].children.size()==1) ans++;
        return;
    }
    if(tree[r].children.size()==0){
        ans++;
        return;
    }
    for(int ch:tree[r].children){
        solve(ch);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;

    for(int i = 0; i<N; i++){
        int par_node; cin>>par_node;
        tree[i].parent = par_node;
        if(par_node != -1){
            tree[par_node].children.push_back(i);
        }
        else{
            root = i;
        }
    }

    cin>>K;

    solve(root);
    cout<<ans;
}