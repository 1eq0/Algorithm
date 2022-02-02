#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m; cin>>m;
    int BIT = 0;
    while(m--){
        string op; int x;
        cin>>op;
        if(op=="add"){
            cin>>x;
            BIT |= (1<<x);
        }
        else if(op=="remove"){
            cin>>x;
            BIT &= ~(1<<x);
        }
        else if(op=="check"){
            cin>>x;
            if(BIT & (1<<x)) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(op=="toggle"){
            cin>>x;
            BIT ^= (1<<x);
        }
        else if(op=="all"){
            BIT = (1<<21)-1;
        }
        else{
            BIT = 0;
        }
    }
}