#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;

    for (int i = 0; i < N * 5; i++)
    {
        if (i < N)
        {
            for (int j = 0; j < N * 5; j++)
                cout << "@";

            cout << '\n';
        }
        else if (i >= (N * 5) - N)
        {
            for (int j = 0; j < N * 5; j++)
                cout << "@";

            cout << '\n';
        }
        else
        {
            for (int j = 0; j < N; j++)
                cout << "@";

            cout << '\n';
        }
    }

    return 0;
}