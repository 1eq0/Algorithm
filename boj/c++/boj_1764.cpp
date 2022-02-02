#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int N,M;
set<string> s1;
vector<string> v;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin>>N>>M;

    while(N--){
        string str;
        cin>>str;
        s1.insert(str);
    }
    while(M--){
        string str;
        cin>>str;
        if(s1.count(str)) v.push_back(str);
    }
    sort(v.begin(),v.end());
    int size = v.size();
    cout<<size<<"\n";
    for(int i = 0; i<size; i++){
        cout<<v[i]<<"\n";
    }
}