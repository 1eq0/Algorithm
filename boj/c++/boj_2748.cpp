#include <iostream>
using namespace std;

int N;
long long fib[100];

void fibo(int n)
{
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    fibo(N);
    cout << fib[N];
}