#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a, ans;
vector<int> w;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i = 0; i<2*n; i++)
    {
        cin>>a;
        w.push_back(a);
    }

    sort(w.begin(),w.end());

    ans = w[0]+w[2*n-1];
    for(int i = 0; i<n; i++){
        a = w[i] + w[2*n-1-i];
        ans = min(a,ans);
    }

    cout<<ans;
}