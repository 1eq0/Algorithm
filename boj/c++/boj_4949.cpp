#include<iostream>
#include<string>
#include<stack>
using namespace std;

void solve(string str){
    stack<char>s;
    for(int i = 0; i<str.length(); i++){
        //cout<<str[i]<<" ";
        if(str[i]=='(' || str[i]=='['){
            s.push(str[i]);
        }
        else if(str[i]==')' || str[i]==']'){
            if(s.empty()){
                cout<<"no\n";
                return;
            }
            else{
                if(str[i] == ')' && s.top() == '(')
                    s.pop();
                else if(str[i] == ']' && s.top()=='[')
                    s.pop();
                else {
                    cout<<"no\n";
                    return;
                }
            }
        }
    }
    if(!s.empty()) cout<<"no\n";
    else cout<<"yes\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1){
        string str;
        getline(cin,str);
        if(str.length()==1 && str[0] == '.') break;
        solve(str);
    }
}
