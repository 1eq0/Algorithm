#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, I_start, I_end;
int mt_end, ans;
vector<pair<int, int>> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> I_start >> I_end;
        m.push_back({I_end, I_start});
    }
    sort(m.begin(), m.end());

    for (int i = 0; i < n; i++)
    {
        if (mt_end > m[i].second)
            continue;
        mt_end = m[i].first;
        ans++;
    }
    cout << ans;
}