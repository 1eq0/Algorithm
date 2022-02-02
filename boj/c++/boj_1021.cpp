#include<iostream>
#include<deque>
using namespace std;

int N,M;
deque<int>dq;
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>N>>M;
    for(int i = 1; i<=N; i++)
        dq.push_back(i);
    while(M--){
        int num;
        cin>>num;
        
        int op1=0,op2=0;
        for(int i = 0; i<dq.size(); i++)
        {
            if(dq[i] == num){
                op1 = i;
                op2 = dq.size()-i;
                break;
            }
        }
        if(op1<op2){
            while(dq.front()!=num){
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                ans++;
            }
            dq.pop_front();
        }
        else{
            while(dq.front()!=num){
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                ans++;
            }
            dq.pop_front();
        }
    }
    cout<<ans;
}