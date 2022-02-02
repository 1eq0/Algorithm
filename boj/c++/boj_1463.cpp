#include <iostream>
using namespace std;

int N;
long long dp[10000001];

void solve()
{
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= 1000000; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    solve();
    cout << dp[N];
}