#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout<<fixed;
    cout.precision(4);

    map<string,int> m;
    string str;
    double n = 0;
    while(getline(cin,str)){
        m[str]++;
        n++;
    }

    for(auto a : m)
        cout<<a.first<<" "<<a.second/n*100<<"\n";
}
