#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i = 1; i<=N; i++){
        q.push(i);
    }

    while(q.size()!=1){
        q.pop();
        int top = q.front();
        q.pop();
        q.push(top);
    }
    cout<<q.front();
}