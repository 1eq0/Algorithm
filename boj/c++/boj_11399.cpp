#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;

    while(N--){
        int p; cin>>p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());

    int size = v.size();
    int ans = 0; int sum = 0;
    for(int i = 0; i<size; i++){
        sum+=v[i];
        ans+=sum;
    }
    cout<<ans;   
}