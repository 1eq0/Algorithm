#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    float x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    float dx = x1 - x2, dy = y1 - y2;
    x3 += dx;
    y3 += dy;

    float m1 = (y2 - y1) / (x2 - x1);
    float m2 = (y3 - y1) / (x3 - x1);

    cout << m1 << " " << m2 << "\n";

    if (m1 == m2)
        cout << "0\n";
    else if (m1 > 0)
    {
        if (m1 > m2)
            cout << "1\n";
        else
            cout << "-1\n";
    }
    else
    {
    }
}