#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int N, T, G;
int num[100000];

int inverseB(int n){
    if(n == 0) return 0;
    int ret = n;
    int i = 1;
    while((ret/i)>=0){
        i *= 10;
        if(ret/i<=0) {i/=10; break;}
    }
    ret += i;
    ret /= 2;
    return ret;
}

int cnt = 0;
void escape(int n){
    //if(n>99999) cout<<"ANG";
    if(n==G) {
        if(num[n]>T) cout<<"ANG";
        else cout<<num[n];}
    
    else{
        /*if(n==N) num[n] = 0;
        else if(B(n)!=n && B(n)<=G) num[B(n)] = num[n] + 1;
        if(num[n+1]== -1) num[n+1] = num[n] + 1;
        escape(n+1);*/
    }
}

int main(){
    /*cin>>N>>T>>G;
    memset(num,-1,sizeof(num));
    escape(N);
    cout<<endl;
    for(int i = N; i<=G; i++)
        cout<<num[i];*/
    cin>>N;
    cout<<inverseB(N);
}