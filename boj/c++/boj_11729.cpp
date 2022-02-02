#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int n;

const int start = 1;
const int rest = 2;
const int goal = 3;


void HaNoi(int num, int from, int to, int tmp)
{
    if(num==1) cout<<from<<" "<<to<<endl; // 원판 하나면 무조건 goal로 보냄
    else {  // 원판이 하나가 아니라면 n-1개를 rest로 보내고 n번째 원판을 goal로
       HaNoi(num-1,from,tmp,to);
       HaNoi(1,from,to,tmp);
       HaNoi(num-1,tmp,to,from);
    }
}

int main()
{
    cin>>n;
    int k = pow(2,n)-1;
    cout<<k<<endl;
    HaNoi(n,start,goal,rest);
}