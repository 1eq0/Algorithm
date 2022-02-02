#include<iostream>
#include<queue>
using namespace std;

int N,K;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>K;

    queue<int> q;
    for(int i = 0; i<N; i++)
        q.push(i+1);
    
    cout<<"<";
    while(q.size()>1){
        for(int i = 0; i<K-1; i++)
        {
            int a = q.front();
            q.pop();
            q.push(a);
        }

        cout<<q.front()<<", ";
        q.pop();
    }
    
    cout<<q.front()<<">";
}