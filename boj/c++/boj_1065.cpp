#include<iostream>
using namespace std;

int N;

bool isHansoo(int num){
    int a = num/100;
    int b = (num%100)/10;
    int c = num%10;

    return (a-b == b-c);
}

int result;
void Hansoo(int num){
    if(num<100) {result = num;} 
    if(num==N) {
        if(isHansoo(num)) result++;
        cout<<result;}
    else{
        if(isHansoo(num)) result++;
        Hansoo(num+1);
    }
    
    
}

int main(){
    cin>>N;
    Hansoo(1);
}