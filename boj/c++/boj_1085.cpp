#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x,y,w,h;
    cin>>x>>y>>w>>h;

    cout<<min(min(w-x,x),min(h-y,y));
}