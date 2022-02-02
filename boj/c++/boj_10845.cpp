#include<iostream>
#include<queue>
#include<string>
using namespace std;

int N;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    while(N--){
        string op;
        cin>>op;
        if(op=="push"){
            int x; cin>>x;
            q.push(x);
        }
        else if(op=="pop"){
            if(q.empty()) cout<<-1<<"\n";
            else{
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
        else if(op=="size"){
            cout<<q.size()<<"\n";
        }
        else if(op=="empty"){
            if(q.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(op=="front"){
            if(q.empty()) cout<<-1<<"\n";
            else cout<<q.front()<<"\n";
        }
        else{
            if(q.empty()) cout<<-1<<"\n";
            else cout<<q.back()<<"\n";
        }
    }

}