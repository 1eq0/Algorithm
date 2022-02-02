#include<iostream>
using namespace std;

int NR,NC;
int squre[100][100] = { };

int sum(int y, int x)
{
    int ret = 0;
    for(int i = y; i<y+3; i++)
    {
        for(int j = x; j<x+3; j++)
            ret += squre[y+i][x+j];
    }
    cout<<ret<<" ";
    return ret;
}

int result, row, column;
void grid(int y, int x){
        int cal = sum(y,x);
        if(cal>result) {
            result = cal;
            row = y; column = x;
        }
}

int main(){
    cin>>NR>>NC;
    for(int i = 0; i<NR; i++)
        for(int j = 0; j<NC; j++)
            cin>>squre[i][j];
    
    for(int i = 0; i<<NR-3; i++)
        for(int j = 0; j<<NC-3; j++)
            grid(i,j);
    cout<<result<<endl;
    cout<<row+1<<" "<<column+1;
}