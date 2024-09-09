#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    int ans = n;
    while (1) {
        ans += n / m;
        n /= m;
        if (n < m)
            break;
    }
    cout << ans << '\n';
}