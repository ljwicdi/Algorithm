
#include <iostream>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    bool chk[2][2] = {false, };
    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        chk[x % 2][y % 2] = true;
    }
    
    if (chk[0][0] && chk[0][1] && chk[1][0] && chk[1][1]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
