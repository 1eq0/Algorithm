#include<iostream>
using namespace std;

const int MAX = 1e5;
int N;
int factors[MAX+1];

void mul(int n){
    for(int i = 2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            factors[i]++;
        }
    }
    if(n!=1) factors[n]++;
}
void div(int n){
    for(int i = 2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            factors[i]--;
        }
    }
    if(n!=1) factors[n]--;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    int num; char c;
    
    cin>>num;
    num = num>0?num:-1*num;
    if(num) mul(num);
    else factors[num] = 1;

    for(int i = 1; i<N; i++){
        cin>>c>>num;
        num = num>0?num:-1*num;
        if(num){
            if(c=='/') div(num);
            else mul(num);
        }
        else factors[num] = 1;
    }

    bool check = false;

    for(int i = 2; i<=MAX; i++){
        if(factors[i]<0) {check = true;break;}
    }
    if(factors[0]) cout<<"mint chocolate";
    else if(check) cout<<"toothpaste";
    else cout<<"mint chocolate";
}