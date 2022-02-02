#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        multiset<int> ms;
        int k; cin>>k;
        while(k--){
            string op; int n;
            cin>>op>>n;
            if(op=="I"){
                ms.insert(n);
            }
            else{
                if(ms.empty()) continue;
                if(n==1) ms.erase(--ms.end());
                else ms.erase(ms.begin());    
            }
        }
        if(ms.empty()) cout<<"EMPTY\n";
        else cout<<*(--ms.end())<<" "<<*(ms.begin())<<"\n";
    }
}