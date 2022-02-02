#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;

int male[MAX];
int female[MAX];

int match[MAX][MAX];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i = 1; i<=n; i++)
        cin>>male[i];
    for(int i = 1; i<=m; i++)
        cin>>female[i];

    sort(male+1,male+n+1);
    sort(female+1,female+m+1);
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            match[i][j] = match[i-1][j-1]+abs(male[i]-female[j]);
            if(i>j) match[i][j] = min(match[i][j],match[i-1][j]);
            if(i<j) match[i][j] = min(match[i][j],match[i][j-1]);
        }
    }   
    cout<<match[n][m];
}