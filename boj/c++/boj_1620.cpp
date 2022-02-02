#include<iostream>
#include<map>
#include<string>
using namespace std;

int N,M;
string str;
map<string,int> m1;
map<int,string> m2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i = 1; i<=N; i++){
        cin>>str;
        m1[str] = i;
        m2[i] = str;
    }

    while(M--){
        cin>>str;
        if(str[0] < '0' || '9' < str[0])
            cout<<m1[str]<<"\n";

        else
            cout<<m2[stoi(str)]<<"\n";
    }
}