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
    if(num==1) cout<<from<<" "<<to<<endl; // ���� �ϳ��� ������ goal�� ����
    else {  // ������ �ϳ��� �ƴ϶�� n-1���� rest�� ������ n��° ������ goal��
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