#include <iostream>
using namespace std;

int N;

int main()
{
    cin >> N;

    int result = 0;

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        int num = i;

        while (num != 0)
        {
            sum += (num % 10);
            num /= 10;
        }
        if ((i + sum) == N)
        {
            result = i;
            break;
        }
    }

    cout << result;
}