#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;

double dist(pair<int,int> a, pair<int,int> b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    double minDist = 1e12;
    pair<double,double> ans;
    for(int i = 0; i<n; i++){ //A가 기준
        double maxDist = 0;
        for(int j = 0; j<n; j++){
            maxDist = max(maxDist,dist(v[i],v[j]));           
        } // AB 최댓값 구하기
        if(minDist>=(maxDist/2)){ //AM 최솟값을 만족하는 A 구하기
            minDist = (maxDist/2); 
            ans.first = v[i].first;
            ans.second = v[i].second;
        }
    }

    cout<<ans.first<<" "<<ans.second<<"\n";
}