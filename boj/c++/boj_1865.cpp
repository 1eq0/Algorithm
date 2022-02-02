#include<iostream>
#include<vector>
using namespace std;
#define ll long long

int N,M,W;
const int n_ = 501;
const int inf = 1e9;
int dist[n_][n_];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int TC;cin>>TC;
    while(TC--){
        cin>>N>>M>>W;

        for(int i = 1; i<=N; i++){
		    for(int j = 1; j<=N; j++){
			    if(i==j) dist[i][j] = 0;
			    dist[i][j] = inf;
	        }
        }
  
        for(int i = 0; i<M; i++){
            int A,B,C;
            cin>>A>>B>>C;
            dist[A][B] = min(dist[A][B],C);
            dist[B][A] = min(dist[B][A],C);
        }

        for(int i = 0; i<W; i++){
            int A,B,C;
            cin>>A>>B>>C;
            dist[A][B] = min(dist[A][B],-C);
        }
        
        for(int k = 1; k<=N; k++){
		//정점 k를 경유하는 경우
		    for(int i = 1; i<=N; i++){
			    for(int j = 1; j<=N; j++){
				    dist[i][j] = min( dist[i][j], dist[i][k]+dist[k][j]);
				//최솟값을 갱신해줘야 한다면 갱신
			    }  
		    }
	    }
        
        bool nCycle = false;
        for(int i = 1; i<=N; i++){
		    if(dist[i][i]<0) nCycle = true;
        }
    
        if(nCycle) cout<<"YES\n";
        else cout<<"NO\n";
    }
}