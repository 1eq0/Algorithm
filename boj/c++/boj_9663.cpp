#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

#define MAX

vector<pair<int,int>> isUsed;

int N;
int ans;

bool promising(int row, int col)
{
    for(int i = 0; i<isUsed.size(); i++){
        int r = isUsed[i].first;
        int c = isUsed[i].second;

        if(row == r || col == c || fabs(row-r) == fabs(col-c))
            return false;
    }
    return true;
}

void solve(int row)
{
    if (row == N)
    {
        ans++;
        return;
    }

    for (int j = 0; j < N; j++)
    {
        if (!promising(row + 1, j))
            continue;
        isUsed.push_back(make_pair(row+1,j));
        solve(row+1);
        isUsed.erase(isUsed.end()-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    solve(0);
    cout << ans;
}