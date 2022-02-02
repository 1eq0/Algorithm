#include<iostream>
using namespace std;

int N;
int house[1001][3];
int s[1001][3];

int main()
{
    cin>>N;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<3; j++)
            cin>>house[i][j]; // 0:R, 1:G, 2:B
    }

    for(int i = 0; i<3; i++)
        s[0][i] = house[0][i];

    //s[i][j] : i에 j색으로 칠했을때 i번째까지 드는 비용
    for(int i = 1 ; i<N; i++)
    {
        s[i][0] = min(s[i-1][1],s[i-1][2]) + house[i][0];
        s[i][1] = min(s[i-1][0],s[i-1][2]) + house[i][1];
        s[i][2] = min(s[i-1][0],s[i-1][1]) + house[i][2];
    }
    int ans = min(s[N-1][0],min(s[N-1][1],s[N-1][2]));
    cout<<ans;
}