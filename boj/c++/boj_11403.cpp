#include<iostream>
using namespace std;

int V,E;
const int n_ = 101;
bool dist[n_][n_];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>V;

    for(int i = 1; i<=V; i++){
        for(int j = 1; j<=V; j++){
            int a; cin>>a;
            dist[i][j] = a;
        }
    }

    for(int k = 1; k<=V; k++){
        for(int i = 1; i<=V; i++){
            for(int j = 1; j<=V; j++){
                dist[i][j] = (dist[i][j] || (dist[i][k]&&dist[k][j]));
            }
        }
    }

    for(int i = 1; i<=V; i++){
        for(int j = 1; j<=V; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}