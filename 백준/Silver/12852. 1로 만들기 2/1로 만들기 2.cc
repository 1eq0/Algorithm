#include <iostream>
using namespace std;
#define ll long long

int N;
const int n_ = 10000001;
ll dp[n_];
ll tracking[n_];

void solve()
{
    dp[0] = 0;
    dp[1] = 0;
    tracking[1] = -1;

    for (int i = 2; i <= 1000000; i++)
    {
        dp[i] = dp[i - 1] + 1;
        tracking[i] = i-1;
        if (i % 3 == 0 && dp[i]>dp[i/3]+1){
            dp[i] = dp[i / 3] + 1;
            tracking[i] = i/3;
		}
        if (i % 2 == 0 && dp[i]>dp[i/2]+1)
        {
			dp[i] = dp[i / 2] + 1;
            tracking[i] = i/2;
		}
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    solve();
    
    //answer
    cout << dp[N]<<"\n";
    cout<<N<<" ";
    while(tracking[N] != -1)
    {
    	cout<<tracking[N]<<" ";
    	N = tracking[N];
	}
}