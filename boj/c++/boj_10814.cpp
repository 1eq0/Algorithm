#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<pair<int,pair<int,string>>> v;

bool cmp(pair<int,pair<int,string>>a, pair<int,pair<int,string>>b){
    if(a.second.first==b.second.first){
        return a.first<b.first;
    }
    return a.second.first<b.second.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin>>N;
    for(int i = 0; i<N ;i++){
        int age; string name;
        cin>>age>>name;
        v.push_back({i,{age,name}});
    }
    sort(v.begin(),v.end(),cmp);

    int size = v.size();
    for(int i = 0; i<size; i++){
        cout<<v[i].second.first<<" "<<v[i].second.second<<"\n";
    }
}