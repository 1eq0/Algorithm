#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int> > work[];
int result[16];
int N;

void ans(int num){
    int t = work[num].front().first;
    int p = work[num].front().second;


    
}

int main()
{
    cin>>N;
    
    for(int i = 1; i<=N; i++)
    {
        int T,P;
        cin>>T>>P;
        work[i].push_back(make_pair(T,P));
    }

}