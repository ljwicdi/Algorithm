
#include <iostream>
using namespace std;
int main()
{
    int M, K;
    cin >> M >> K;
    if (M % K == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
