#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ans;
bool isUsed[9];

void solve(int level)
{
    if(level == M){
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i = 1; i<=N; i++){
        if(isUsed[i]) continue;
        isUsed[i] = true;
        ans.push_back(i);
        solve(level+1);
        ans.pop_back();
        isUsed[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    solve(0);
}