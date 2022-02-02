#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, ans, cnt;
vector<int> dec_a;
vector<int> ndec_a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 10 == 0)
            dec_a.push_back(a);
        else
            ndec_a.push_back(a);
    }

    sort(dec_a.begin(),dec_a.end());
    for (int i = 0; i < dec_a.size(); i++)
    {
        if (dec_a[i] == 10)
            ans++;
        else
        {
            while (dec_a[i] != 10 && cnt < m)
            {
                dec_a[i] -= 10;
                cnt++;
                ans++;
                if (cnt == m)
                    break;
            }
            if(cnt!=m || dec_a[i]==10) ans++;
        }
    }

    for (int i = 0; i < ndec_a.size(); i++)
    {
        if (ndec_a[i] < 10)
            continue;
        if (cnt == m)
            break;
        else if (cnt < m)
        {
            while ((ndec_a[i] > 10) && (ndec_a[i]>10) && cnt < m)
            {
                ndec_a[i] -= 10;
                cnt++;
                ans++;
            }
        }
    }

    cout << ans;
}