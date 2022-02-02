#include<iostream>
#include<string>
#include<map>
using namespace std;

int N,ans;
map<string,int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N; 
    string str;
    for(int i = 0; i<N; i++){
        cin>>str;
        m[str] = i;
    }
    string car[1001];
    for(int i = 0; i<N ;i++){
        cin>>str;
        car[i] = str;
    }
    
    for(int i = 0; i<N; i++){
        bool check = false;
        for(int j = i+1; j<N; j++){
            if(m[car[i]]>m[car[j]]) check = true;
        }
        if(check) ans++;
    }
    cout<<ans;
}