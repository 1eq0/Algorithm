#include<iostream>
#include<algorithm>
using namespace std;

int N;
int num[1000001];

void makeOne(int idx)
{
    if(idx == 1) num[idx] = 0;
    else{
        makeOne(idx-1);
        num[idx] = num[idx-1]+1;
        if(idx%2==0) num[idx] = min(num[idx], num[idx/2]+1);
        if(idx%3==0) num[idx] = min(num[idx], num[idx/3]+1);
    }
}

int main()
{
    cin>>N;
    makeOne(N);
    cout<<num[N];
}