#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, ans;
vector<int> level;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        level.push_back(a);
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (level[i-1] >= level[i])
        {
            while (level[i-1] >= level[i])
            {
                if (level[i-1] <= 1)
                    break;
                level[i-1]--;
                ans++;
            }
        }
    }
    cout << ans;
}