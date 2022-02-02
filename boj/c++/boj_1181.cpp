#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N;
vector<string> v;

bool cmp(string a, string b){
    if(a.length()==b.length()){
        return a<b;
    }
    else return a.length()<b.length();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    while(N--){
        string str;
        cin>>str;
        v.push_back(str);
    }

    sort(v.begin(),v.end(),cmp);
    v.erase(unique(v.begin(),v.end()),v.end());
    
    int size = v.size();
    for(int i = 0; i<size; i++){
        cout<<v[i]<<"\n";
    }
}