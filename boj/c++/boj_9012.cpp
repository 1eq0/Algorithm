#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;cin>>T;
    while(T--){
        stack<char> s;
        bool check = false;
        string str; cin>>str;
        int len = str.length();
        for(int i = 0; i<len; i++){
            if(str[i]=='(') s.push(str[i]);
            else{
                if(s.empty()) {check = true; break;}
                else{
                    s.pop();
                }
            }
        }
        if(!s.empty()) check = true;

        if(check) cout<<"NO\n";
        else cout<<"YES\n";
    }
}