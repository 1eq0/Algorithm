#include <iostream>
using namespace std;

long long MOD = 1000000009;

int N, T;
long long dp[10000001];

void solve()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++)
    {
        dp[i] += dp[i - 1] + dp[i - 2] + dp[i - 3];
        dp[i] %= MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    solve();

    while (T--)
    {
        cin >> N;
        cout << dp[N] << "\n";
    }
}