#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V,E;
const int n_ = 101,inf = 1e9;
int dist[n_][n_];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>V>>E;

    for(int i = 1; i<=V; i++){
		for(int j = 1; j<=V; j++){
			if(i==j) continue;
			dist[i][j] = inf;
	    }
    }

    for(int i = 0; i<E; i++){
        int a,b;
        cin>>a>>b;
        dist[a][b] = dist[b][a] = 1;
    }

    for(int k = 1; k<=V; k++){
        for(int i = 1; i<=V; i++){
            for(int j = 1; j<=V; j++){
                dist[i][j] = dist[j][i] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    vector<pair<int,int>>ans;

    for(int i = 1; i<=V; i++){
        int vacon = 0;
        for(int j = 1; j<=V; j++){
            vacon += dist[i][j];
        }
        ans.push_back({vacon,i});
    }

    sort(ans.begin(),ans.end());
    cout<<ans[0].second;
    
}