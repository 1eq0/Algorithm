#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int D[10001];
int dp[10005][505][2];

void run()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (j >= 2)
            {
                dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
                dp[i][j][1] = dp[i - 1][j - 1][1] + D[i];
            }
            else if (j == 1)
            {
                dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
                dp[i][j][1] = dp[i - 1][j - 1][0] + D[i];
            }
            else
            {
                dp[i][j][0] = max({dp[i - 1][j + 1][1], dp[i - 1][j + 1][0], dp[i - 1][j][0]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> D[i];

    run();
    cout << dp[N][0][0];
}