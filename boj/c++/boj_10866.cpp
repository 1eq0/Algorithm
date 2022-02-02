#include<iostream>
#include<queue>
#include<string>
using namespace std;

int N;
deque<int> dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    while(N--){
        string op;
        cin>>op;
        if(op=="push_front"){
            int x; cin>>x;
            dq.push_front(x);
        }
        else if(op=="push_back"){
            int x; cin>>x;
            dq.push_back(x);
        }
        else if(op=="pop_front"){
            if(dq.empty()) cout<<-1<<"\n";
            else{
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if(op=="pop_back"){
            if(dq.empty()) cout<<-1<<"\n";
            else{
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
        }
        else if(op=="size"){
            cout<<dq.size()<<"\n";
        }
        else if(op=="empty"){
            if(dq.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(op=="front"){
            if(dq.empty()) cout<<-1<<"\n";
            else cout<<dq.front()<<"\n";
        }
        else{
            if(dq.empty()) cout<<-1<<"\n";
            else cout<<dq.back()<<"\n";
        }
    }

}