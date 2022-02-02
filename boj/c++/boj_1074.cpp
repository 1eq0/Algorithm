#include <iostream>
using namespace std;
#define ll long long

const int dx[4] = {0, 1, 0, 1};
const int dy[4] = {0, 0, 1, 1};

ll n, r, c;

ll ans;
void findZ(ll size, ll y, ll x)
{
    if(size == 0 || (y==r && x==c)) return;

    ll half = size/2;

    if(y<=r && r<y+half && x<=c && c<x+half){
        findZ(half,y,x);
    }
    else if(y<=r && r<y+half && x+half<=c && c<x+2*half){    
        ans += half*half;
        findZ(half,y,x+half);
    }
    else if(y+half<=r && r<y+2*half && x<=c && c<x+half){
        ans += 2*half*half;
        findZ(half,y+half,x);
    }
    else{
        ans += 3*half*half;
        findZ(half,y+half,x+half);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> c;
    findZ(1<<n, 0, 0);
    cout<<ans;
}