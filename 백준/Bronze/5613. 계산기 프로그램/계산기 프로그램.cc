#include <iostream>
using namespace std;

int main()
{
    char c;
    long long n, sum;

    cin >> n;

    sum = n;

    while (1)
    {
        cin >> c;

        if (c == '=')
        {
            cout << sum << '\n';
            return 0;
        }

        cin >> n;

        if (c == '+')
            sum += n;
        else if (c == '-')
            sum -= n;
        else if (c == '*')
            sum *= n;
        else if (c == '/')
            sum /= n;
    }

    cout << sum << '\n';

    return 0;
}