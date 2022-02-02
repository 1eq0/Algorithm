#include <iostream>
#include <queue>
using namespace std;

const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
int dist[101][101][101];
int box[101][101][101];
queue<pair<int, pair<int, int>>> q;

int M, N, H;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];
                dist[i][j][k] = -1;
                if (box[i][j][k] == 1)
                {
                    q.push({i, {j, k}});
                    dist[i][j][k] = 0;
                }
            }
        }
    }
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second.first;
        int curZ = q.front().second.second;
        q.pop();
        for (int k = 0; k < 6; k++)
        {
            int nextX = curX + dx[k];
            int nextY = curY + dy[k];
            int nextZ = curZ + dz[k];
            if (nextX < 0 || nextX >= H || nextY < 0 || nextY >= N || nextZ < 0 || nextZ >= M)
                continue;
            if (box[nextX][nextY][nextZ] == 0 && dist[nextX][nextY][nextZ] == -1)
            {
                q.push({nextX, {nextY, nextZ}});
                box[nextX][nextY][nextZ] = 1;
                dist[nextX][nextY][nextZ] = dist[curX][curY][curZ] + 1;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (box[i][j][k] == 0)
                    ans = -1;
            }
        }
    }
    cout << ans;
}