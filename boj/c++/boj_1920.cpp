#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int A[1000001];

bool bin_search(int n){
    int low = 0, high = N-1;
    int mid;

    while(low <= high){
        mid = (high+low)/2;
        if(n<A[mid])
            high = mid-1;
        else if(n>A[mid])
            low = mid+1;
        else
            return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>A[i];
    }
    sort(A,A+N);
    cin>>M;
    for(int i = 0; i<M; i++){
        int a;
        cin>>a;
        cout<<bin_search(a)<<"\n";
    }
}