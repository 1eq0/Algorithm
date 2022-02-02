#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long LL;
LL m = 1000000007;
LL c[2501]; // Ä«Å»¶õ ¼ö
 
int main()
{
    int t, l;
    c[0] = 1;
    for (int i = 0; i < 2500; i++) {
        for (int j = 0; j <= i; j++) {
            c[i + 1] += c[j] * c[i - j];
            c[i + 1] %= m;
        }
    }
    cin >> t;
    while (t--) {
        cin >> l;
        l % 2 == 0 ? printf("%lld\n", c[l / 2]) : puts("0");
    }
    return 0;
}
