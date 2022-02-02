#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1){
        string str1,str2;
        cin>>str1;
        if(str1=="0") break;

        str2=str1;
        reverse(str2.begin(),str2.end());

        if(str1==str2) cout<<"yes\n";
        else cout<<"no\n";
        
    }
}