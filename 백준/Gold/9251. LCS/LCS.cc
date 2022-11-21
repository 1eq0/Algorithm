#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;

string str1;
string str2;

int match[MAX][MAX];

int main()
{
    cin>>str1>>str2;
        
    for(int i = 1; i<=str1.size(); i++){
        for(int j = 1; j<=str2.size(); j++){
            if(str1[i-1]==str2[j-1]) match[i][j] = match[i-1][j-1]+1;
            else match[i][j] = max(match[i-1][j],match[i][j-1]);
        }
    }   
    cout<<match[str1.size()][str2.size()];
}