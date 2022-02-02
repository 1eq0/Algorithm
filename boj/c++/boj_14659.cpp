#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ans, cnt, hmax;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
    }

    cnt = 0;
    hmax = v[0];
    for (int i = 0; i < n; i++)
    {
        if (hmax <= v[i])
        {
            hmax = v[i];
            ans = max(ans, cnt);
            cnt = 0;
        }
        else
            cnt++;
    }
    ans = max(ans, cnt);
    cout << ans;
}