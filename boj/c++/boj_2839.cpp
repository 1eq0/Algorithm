#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    ans = -1;
    
    for (int i = n / 5; i >= 0; i--)
    {
        if ((n - (5 * i)) >= 0 && ((n - (5 * i)) % 3) == 0)
        {
            ans = i + ((n - (5 * i)) / 3);
            break;
        }
    }

    cout << ans;
}