#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int h,w,n;
        cin>>h>>w>>n;

        int floor, room;
        room = n/h+1;
        floor = n%h;
        if(floor == 0) {room--;floor = h;}

        cout<<(floor*100+room)<<"\n";
    }
}