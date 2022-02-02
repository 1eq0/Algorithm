#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<int> answer;

void printAnswer(){
    for(int i = 0; i < answer.size(); i++)
        cout<<answer[i]<<" ";
}

void solve(int level){
    if(level == M)
    {
        printAnswer();
        cout<<"\n";
        return;
    }

    int smallest = answer.empty() ? 1 : answer.back()+1;
    for(int i = smallest; i<=N; i++){
        answer.push_back(i);
        solve(level+1);
        answer.pop_back();
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    solve(0);
}