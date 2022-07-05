#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef vector<vector<ll> > matrix;
const ll MOD = 1e6;

ll N;
matrix op = {{1,1},{1,0}};

//행렬 곱
matrix dot(matrix &a, matrix &b){
  ll size = a.size();
  matrix ret(size, vector<ll>(size));
  for(ll i = 0; i < size; i++) {
		for(ll j = 0; j < size; j++) {
      ll sum = 0;
			for(ll k = 0; k < size; k++)
				sum += a[i][k]*b[k][j];
			ret[i][j] = (ret[i][j] + sum) % MOD;
		}
	}
	return ret;
}

//행렬 거듭제곱
matrix power (matrix a, ll n){
  ll size = a.size();
  matrix ret(size, vector<ll>(size));
  //단위행렬
  for(ll i = 0; i<size; i++){
    ret[i][i] = 1;
  }
  while(n>0){
    if(n%2==1){
      ret = dot(ret,a);
    }
    n = n>>1;
    a = dot(a,a);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> N;
  matrix ans = (power(op,N-1));
  cout << (ans[1][0]+ans[1][1]) % MOD;
}
