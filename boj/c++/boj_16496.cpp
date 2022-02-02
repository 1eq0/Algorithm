#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return a+b>b+a;
}

string nums[1010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    sort(nums,nums+n,cmp);
    if(nums[0]=="0") cout<<0;
    else{
        for(int i = 0; i<n; i++){
            cout<<nums[i];
        }
    }
}