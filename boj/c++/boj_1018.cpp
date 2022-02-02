#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char board[50][50];
int black, white, ans;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        scanf("\n");
        for (int j = 0; j < M; j++)
        {
            scanf("%c", &board[i][j]);
        }
    }

    ans = 70;
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            white = 0;
            black = 0;
            for (int a = i; a < i + 8; a++)
            {
                for (int b = j; b < j + 8; b++)
                {
                    if (board[a][b] == 'W')
                    {
                        if ((a + b) % 2 == 0)
                            black++;
                        else
                            white++;
                    }
                    if (board[a][b] == 'B')
                    {
                        if ((a + b) % 2 == 0)
                            white++;
                        else
                            black++;
                    }
                }
            }
            ans = min({ans, white, black});
        }
    }

    cout << ans;
}