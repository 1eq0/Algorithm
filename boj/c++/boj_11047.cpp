#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int n,k,a,ans;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end(),greater<int>());

    for(int i = 0; i<n; i++)
    {
        if(k<v[i]) continue;
        ans += (k/v[i]);
        k -= (k/v[i])*v[i];
    }
    cout<<ans;
}