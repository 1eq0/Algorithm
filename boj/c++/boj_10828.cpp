#include<iostream>
#include<stack>
#include<string>
using namespace std;

int N;
stack<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    while(N--){
        string op;
        cin>>op;
        if(op=="push"){
            int x; cin>>x;
            s.push(x);
        }
        else if(op=="pop"){
            if(s.empty()) cout<<-1<<"\n";
            else{
                cout<<s.top()<<"\n";
                s.pop();
            }
        }
        else if(op=="size"){
            cout<<s.size()<<"\n";
        }
        else if(op=="empty"){
            if(s.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else{
            if(s.empty()) cout<<-1<<"\n";
            else cout<<s.top()<<"\n";
        }
    }

}