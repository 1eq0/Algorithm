#include<iostream>
#define MAX 2187
using namespace std;

int n;
int board[MAX][MAX] = {2, };
int one,zero,m_one = 0;

bool allone(int size, int y, int x)
{
    for(int dy = 0; dy<size; dy++)
        for(int dx = 0; dx<size; dx++)
            if(board[y+dy][x+dx]!=1) return false;
    return true;
}
bool allzero(int size, int y, int x)
{
    for(int dy = 0; dy<size; dy++)
        for(int dx = 0; dx<size; dx++)
            if(board[y+dy][x+dx]!=0) return false;
    return true;
}
bool allminus(int size, int y, int x)
{
    for(int dy = 0; dy<size; dy++)
        for(int dx = 0; dx<size; dx++)
            if(board[y+dy][x+dx]!=-1) return false;
    return true;
}

void paper(int size, int y, int x)
{
    if(allone(size,y,x)) one++;
    else if(allzero(size,y,x)) zero++;
    else if(allminus(size,y,x)) m_one++;

    else{
        int third = size/3;
        paper(third,y,x);
        paper(third,y,x+third);
        paper(third,y,x+(third*2));
        paper(third,y+third,x);
        paper(third,y+third,x+third);
        paper(third,y+third,x+(third*2));
        paper(third,y+(third*2),x);
        paper(third,y+(third*2),x+third);
        paper(third,y+(third*2),x+(third*2));     
    }
}

int main()
{
    cin>>n;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
           cin>>board[i][j];
        }
    }

    paper(n,0,0);
    cout<<m_one<<endl;
    cout<<zero<<endl;
    cout<<one;
}