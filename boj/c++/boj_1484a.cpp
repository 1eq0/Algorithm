#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

ll G, a =1, b=1;
bool chk = false;

ll sq(ll n)
{
	return n * n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> G;

	while (!(b - a == 1 && sq(b) - sq(a) > G))
	{
		if (sq(b) - sq(a) <= G) b++;
		else a++;

		if (sq(b) - sq(a) == G) { cout << b << '\n'; chk = true; }
	}

	if (!chk) cout << -1 << '\n';

	return 0;
}