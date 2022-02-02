#include<iostream>
using namespace std;

int n,m;

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

int main(){
    scanf("%d:%d",&n,&m);
    int g = n>m?gcd(n,m):gcd(m,n);

    cout<<n/g<<":"<<m/g;
}