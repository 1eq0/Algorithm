#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v, idx;

    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
        idx.push_back(x);
    }

    sort(idx.begin(), idx.end());                         //����
    idx.erase(unique(idx.begin(), idx.end()), idx.end()); //�ߺ�����

    for (int a : v)
    {
        cout << lower_bound(idx.begin(), idx.end(), a) - idx.begin() << " "; //idx �̾Ƴ���
    }
}