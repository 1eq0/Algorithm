//Çà·ÄÀÇ °ö¼À ¼ø¼­
#include<iostream>
using namespace std;

int N;
int M[501][501];
int d[501];

int minmult(int n){
    for(int i = 1; i<=n; i++)
        M[i][i] = 0;

    for(int diagonal = 1; diagonal<=n-1; diagonal++)
    {
        for(int i = 1; i<=n-diagonal; i++)
        {
            int j = i + diagonal;
            M[i][j] = M[i][i]+M[i+1][j]+d[i-1]*d[i]*d[j];
            for(int k = i+1; k<=j-1; k++)
            {
                int cal = M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
                M[i][j] = min(M[i][j],cal);
            }
            if(i==j) M[i][j] = 0;
        }
    }
    return M[1][n];  
}

int main()
{
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>d[i]>>d[i+1];
    }

    cout<<minmult(N);
}