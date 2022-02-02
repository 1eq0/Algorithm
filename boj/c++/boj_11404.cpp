#include<iostream>
using namespace std;

int V,E;
const int n_ = 101, inf = 1e9;
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
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b],c);
    }

    for(int k = 1; k<=V; k++){
        for(int i = 1; i<=V; i++){
            for(int j = 1; j<=V; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i = 1; i<=V; i++){
        for(int j = 1; j<=V; j++){
            if(dist[i][j]==inf) cout<<"0 ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}