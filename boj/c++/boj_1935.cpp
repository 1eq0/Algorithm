#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<double>s;
int op[30];

int N;
string str;
double a,b;

void solve(){
    for(int i = 0; i<str.length(); i++)
    {
        if('A'<=str[i] && str[i]<='Z')
            s.push(op[str[i]-'A']);
        else{
            if(!s.empty()){
                b=s.top();
                s.pop();
                a=s.top();
                s.pop();
            }
            switch (str[i]){
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(a-b);
                    break;
                case '*':
                    s.push(a*b);
                    break;
                case '/':
                    s.push(a/b);
                    break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cout<<fixed;
    cout.precision(2);

    cin>>N;
    cin>>str;
    for(int i = 0; i<N; i++)
        cin>>op[i];
    
    solve();
    cout<<s.top()<<"\n";
}